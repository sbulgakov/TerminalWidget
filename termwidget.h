/*

MIT license

Copyright 2024 Stanislav Bulgakov

Permission is hereby granted, free of charge, to any
person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the
Software without restriction, including without
limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice
shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#ifndef TERMWIDGET_H
#define TERMWIDGET_H

#include <QWidget>

#include <QPlainTextEdit>
#include <QProcess>
#include <QMenu>

class TermWidget : public QWidget
{
    Q_OBJECT
    
    QPlainTextEdit *out;
    int             outEnd;
    
    QProcess       *proc;
    
    QMenu          *menu;
    QAction        *menuActCopy;
    QAction        *menuActPaste;
    QAction        *menuActSelectAll;
    QAction        *menuActClear;
    
#ifdef Q_OS_WIN32
    QByteArray      inp;
#endif
    
public:
    TermWidget(QWidget *parent = 0);
   ~TermWidget();
    
public slots:
    int  setTextCursorAtInput();
    int  setTextCursorAtEnd();
    
    void paste();
    
    void execute();
    
    void processInput();
    
protected slots:
    void processOutput();
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void error(QProcess::ProcessError error);
    
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // TERMWIDGET_H
