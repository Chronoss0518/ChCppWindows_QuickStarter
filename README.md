### 概要

このProjectは`ChCppLibrary`のサンプルとして組み上げたものです。
利用しているライブラリは以下のものになります。

- [ChCppBaseLibrary](https://github.com/Chronoss0518/ChCppBaseLibrary)
- [ChCppWinLibrary](https://github.com/Chronoss0518/ChCppWinLibrary)

### 切り替え方法

main.cppにある以下のコメントアウトを切り替えることで、内容が切り替わるようになっています。

```C++

//挙動を確認したい項目のコメントアウトを外してください//

//// Windowの作り方//
//#include"CreateWindow.h"//←切り替えられる場所//

//// Bitmap画像のロード及び表示//
//#include"DrawImage.h"//←切り替えられる場所//

//// MessageBoxの表示//
//#include"DrawMessageBox.h"//←切り替えられる場所//

//// Buttonの作成および表示//
//#include"DrawButton.h"//←切り替えられる場所//

//// FileDialogの表示//
#include"DrawFileDialog.h"//←切り替えられる場所//

```

サンプルコードは以下の通りです。

- [CreateWindow](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/CreateWindow.h)
  - WindowsのWindowを表示するためのSampleです
- [DrawImage](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawImage.h)
  - Bitmapを画面上に表示するSampleです
- [DrawMessageBox](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawMessageBox.h)
  - MessageBoxを表示するためのSampleです
- [DrawButton](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawButton.h)
  - Buttonを表示し押下した際にMessageBoxを表示するSampleです
- [DrawFileDialog](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawFileDialog.h)
  - Fileを選択するためのDialogを表示し、選択したファイルの絶対パスをMessageBoxで表示するためのSampleです