#include "effect.h"

#include "panels/panels.h"
#include "panels/viewer.h"
#include "ui/viewerwidget.h"
#include "ui/collapsiblewidget.h"
#include "effects/effects.h"
#include "panels/project.h"
#include "project/undo.h"
#include "ui/labelslider.h"
#include "ui/colorbutton.h"
#include "ui/comboboxex.h"
#include "ui/fontcombobox.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QTextEdit>

Effect::Effect(Clip* c, int t, int i) : parent_clip(c), type(t), id(i) {
    container = new CollapsibleWidget();
    if (type == EFFECT_TYPE_VIDEO) {
        container->setText(video_effect_names[i]);
    } else if (type == EFFECT_TYPE_AUDIO) {
        container->setText(audio_effect_names[i]);
    }
    connect(container->enabled_check, SIGNAL(clicked(bool)), this, SLOT(checkbox_command()));
    connect(container->enabled_check, SIGNAL(clicked(bool)), this, SLOT(field_changed()));
    ui = new QWidget();

    ui_layout = new QGridLayout();
    ui->setLayout(ui_layout);
	container->setContents(ui);
}

Effect::~Effect() {
	for (int i=0;i<rows.size();i++) {
		delete rows.at(i);
	}
}

EffectRow* Effect::add_row(const QString& name) {
	EffectRow* row = new EffectRow(this, ui_layout, name, rows.size());
	rows.append(row);
	return row;
}

EffectRow* Effect::row(int i) {
	return rows.at(i);
}

void Effect::refresh() {
    qDebug() << "[WARNING] Tried to init base Effect class - type:" << type << "- id:" << id;
}

void Effect::field_changed() {
	panel_viewer->viewer_widget->update();
}

void Effect::checkbox_command() {
    CheckboxCommand* c = new CheckboxCommand(static_cast<QCheckBox*>(sender()));
    undo_stack.push(c);
}

bool Effect::is_enabled() {
    return container->enabled_check->isChecked();
}

Effect* Effect::copy(Clip*) {return NULL;}
void Effect::load(QXmlStreamReader*) {}
void Effect::save(QXmlStreamWriter*) {}
void Effect::process_gl(int*, int*) {}
void Effect::post_gl() {}
void Effect::process_audio(uint8_t*, int) {}

/* Effect Row Definitions */

EffectRow::EffectRow(Effect *parent, QGridLayout *uilayout, const QString &n, int row) : parent_effect(parent), ui(uilayout), name(n), ui_row(row) {
	ui->addWidget(new QLabel(name), row, 0);
}

EffectField* EffectRow::add_field(int type) {
	EffectField* field = new EffectField(parent_effect, type);
	fields.append(field);
	QWidget* element = field->get_ui_element();
	ui->addWidget(element, ui_row, fields.size());
	return field;
}

EffectRow::~EffectRow() {
	for (int i=0;i<fields.size();i++) {
		delete fields.at(i);
	}
}

/* Effect Field Definitions */

EffectField::EffectField(Effect *parent, int t) : type(t) {
	switch (t) {
	case EFFECT_FIELD_DOUBLE:
	{
		LabelSlider* ls = new LabelSlider();
		ui_element = ls;
		QObject::connect(ls, SIGNAL(valueChanged()), parent, SLOT(field_changed()));
	}
		break;
	case EFFECT_FIELD_COLOR:
	{
		ui_element = new ColorButton();
	}
		break;
	case EFFECT_FIELD_STRING:
	{
		QTextEdit* edit = new QTextEdit();
		edit->setUndoRedoEnabled(true);
		ui_element = edit;
	}
		break;
	case EFFECT_FIELD_BOOL:
	{
		QCheckBox* cb = new QCheckBox();
		ui_element = cb;
		QObject::connect(cb, SIGNAL(toggled(bool)), parent, SLOT(field_changed()));
		QObject::connect(cb, SIGNAL(clicked(bool)), parent, SLOT(checkbox_command()));
	}
		break;
	case EFFECT_FIELD_COMBO:
	{
		ui_element = new ComboBoxEx();
	}
		break;
	case EFFECT_FIELD_FONT:
	{
		ui_element = new FontCombobox();
	}
		break;
	}
}

QWidget* EffectField::get_ui_element() {
	return ui_element;
}

void EffectField::set_enabled(bool e) {
	switch (type) {
	case EFFECT_FIELD_DOUBLE: static_cast<LabelSlider*>(ui_element)->setEnabled(e); break;
	case EFFECT_FIELD_COLOR: static_cast<ColorButton*>(ui_element)->setEnabled(e); break;
	case EFFECT_FIELD_STRING: static_cast<QTextEdit*>(ui_element)->setEnabled(e); break;
	case EFFECT_FIELD_BOOL: static_cast<QCheckBox*>(ui_element)->setEnabled(e); break;
	case EFFECT_FIELD_COMBO: static_cast<ComboBoxEx*>(ui_element)->setEnabled(e); break;
	case EFFECT_FIELD_FONT: static_cast<FontCombobox*>(ui_element)->setEnabled(e); break;
	}
}

double EffectField::get_double_value() {
	return static_cast<LabelSlider*>(ui_element)->value();
}

void EffectField::set_double_value(double v) {
	static_cast<LabelSlider*>(ui_element)->set_value(v);
}

void EffectField::set_double_default_value(double v) {
	static_cast<LabelSlider*>(ui_element)->set_default_value(v);
}

void EffectField::set_double_minimum_value(double v) {
	static_cast<LabelSlider*>(ui_element)->set_minimum_value(v);
}

void EffectField::set_double_maximum_value(double v) {
	static_cast<LabelSlider*>(ui_element)->set_maximum_value(v);
}

void EffectField::add_combo_item(const QString& name, const QVariant& data) {
	static_cast<QComboBox*>(ui_element)->addItem(name, data);
}

int EffectField::get_combo_index() {
	return static_cast<QComboBox*>(ui_element)->currentIndex();
}

const QVariant EffectField::get_combo_data() {
	return static_cast<QComboBox*>(ui_element)->currentData();
}

const QString EffectField::get_combo_string() {
	return static_cast<QComboBox*>(ui_element)->currentText();
}

void EffectField::set_combo_index(int index) {
	static_cast<QComboBox*>(ui_element)->setCurrentIndex(index);
}

bool EffectField::get_bool_value() {
	return static_cast<QCheckBox*>(ui_element)->isChecked();
}

void EffectField::set_bool_value(bool b) {
	return static_cast<QCheckBox*>(ui_element)->setChecked(b);
}

const QString EffectField::get_string_value() {
	return static_cast<QTextEdit*>(ui_element)->toPlainText();
}

void EffectField::set_string_value(const QString& s) {
	static_cast<QTextEdit*>(ui_element)->setText(s);
}

const QString EffectField::get_font_name() {
	return static_cast<FontCombobox*>(ui_element)->currentText();
}

QColor EffectField::get_color_value() {
	return static_cast<ColorButton*>(ui_element)->get_color();
}
