# MyNotepad


# MyNotepad-- Basic Features:

    General File: New, Open, Save, Save As, Exit
    General Edit Features: Copy, Cut, Paste, Undo, Redo
    Superscript,Subscript
    General Keyboard Shortcuts
    Bold Toggle
    Subscript Toggle
    Superscript Toggle

# How to run the code?

    Execute file Text-Editor in folder "MyNotepad"

$ ./MyNotepad

# What has been done?

    CREATING A NEW PROJECT : In QT Creator, a QT widgets application is created.

File -> New File or Project -> Application -> QT Widgets Application (Choose) -> Name & Location (Next) -> Desktop Kit (Next) -> Classname: MyTextEditor (Next) -> Finish

    DESIGNING UI : Open mytexteditor.ui file in QT Creator. Drag and Drop a "Text Edit" Input Widget into the editor area. In order to have the text edit widget occupy the whole screen, we add setCentralWidget to the main window.

this->setCentralWidget(ui->textEdit);

Press Ctrl+S (or Cmd+S) to save your changes.

    Add "Text" in menu bar and "Bold" in it. An action is created. Drag the action onto the task bar. Tick checkable for the action.

    To add an icon for "Bold" :

Text-Editor -> add New -> Qt -> Qt Resource File (Choose) -> Name (AppResources) & Location (inside Text-Editor) (Next) -> Finish.

In the appresources.qrc file in "Resources", add a prefix \Images and add a file (bold.png) inside Images. "Edit action" of "Bold Action" -> Icon (select)

    Right Click the action -> "Go to Slot" -> Triggered (bool) (Ok). Function "on_actionBold_triggered(bool checked)" is created in "mytexteditor.cpp" . Add this line inside the function.

checked ? ui->textEdit->setFontWeight(QFont::Bold) :
          ui->textEdit->setFontWeight(QFont::Normal);
          
 SubScript Superscript :
          oid MainWindow::on_actionSuperscript_triggered()
{
    Subscript -> setChecked(false);
    QTextCharFormat format;

    if(Superscript -> isChecked())
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    else
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);

    ui -> textEdit -> mergeCurrentCharFormat(format);
}



void MainWindow::on_actionSubscript_triggered()
{
    Superscript -> setChecked(false);
        QTextCharFormat format;

        if(Subscript -> isChecked())
            format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        else
            format.setVerticalAlignment(QTextCharFormat::AlignNormal);

        ui -> textEdit -> mergeCurrentCharFormat(format);
}



    Build and Run

# Issues / Challenges ?

    To understand the working of checkable action.


        
