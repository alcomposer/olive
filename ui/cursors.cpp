/***

    Olive - Non-Linear Video Editor
    Copyright (C) 2019  Olive Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "cursors.h"

#include <QPixmap>
#include <QCursor>

#include <QDebug>

QCursor Olive::Cursor_LeftTrim;
QCursor Olive::Cursor_RightTrim;
QCursor Olive::Cursor_LeftRipple;
QCursor Olive::Cursor_RightRipple;
QCursor Olive::Cursor_Slip;
QCursor Olive::Cursor_Razor;

QCursor load_cursor(const QString& file, int hotX, int hotY, const bool& right_aligned){
    // load specified file into a pixmap
    QPixmap temp(file);
	temp = temp.scaled(24,24,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // set cursor's horizontal hotspot
    if (right_aligned) {
        hotX = temp.width() - hotX;
    }

    // return cursor
    return QCursor(temp, hotX, hotY);
}

void init_custom_cursors(){
    qInfo() << "Initializing custom cursors";
	Olive::Cursor_LeftTrim    = load_cursor(":/cursors/1_left_32.png",  -1, -1, false);
	Olive::Cursor_RightTrim   = load_cursor(":/cursors/1_right_32.png", -1, -1, false);
	Olive::Cursor_LeftRipple   = load_cursor(":/cursors/3_left_32.png",  -1, -1, false);
	Olive::Cursor_RightRipple  = load_cursor(":/cursors/3_right_32.png", -1, -1, false);
	Olive::Cursor_Slip = load_cursor(":/cursors/4_32.png", -1, -1, false);
	Olive::Cursor_Razor       = load_cursor(":/cursors/5c_32.png",       0, -1, false);
    qInfo() << "Finished initializing custom cursors";
}
