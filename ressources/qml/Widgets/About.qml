import QtQml 2.2
import QtQuick 2.6

import QtQuick.Controls 2.1

Popup {
    id: about_dialog

    modal: true
    focus: true

    // Fixme: better ???
    property real factor: .9
    width: parent.width * factor
    height: parent.height * factor
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    // closePolicy: Popup.OnEscape | Popup.OnPressOutside

    Flickable {
        id: flickable
        anchors.fill: parent

        TextArea.flickable: TextArea {
            id: text_area
            font.pointSize: 12
            readOnly: true
            text: about_text
            textFormat: TextEdit.RichText
            wrapMode: Text.WordWrap

            background: null // suppress bottom line

            onLinkActivated: Qt.openUrlExternally(link)
            // Fixme: hover style
            // http://doc.qt.io/qt-5/richtext-html-subset.html
            // :hover is not supported
        }

        ScrollBar.vertical: ScrollBar { }
    }

    property string about_text : '
<h1>About</h1>

<p><strong>Alpine ToolKit v%1</strong></p>

<p>Copyright © 2017 Fabrice Salvaire</p>

<p><a href="%2">%2</a></p>

<h2>License</h2>

<p>
This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.
</p>

<p>
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
</p>

<p>
You should have received a copy of the GNU General Public License
along with this program.  If not, see <a
href="http://www.gnu.org/licenses">http://www.gnu.org/licenses</a>.
<p>
'.arg(application.version).arg(application.home_page)
}
