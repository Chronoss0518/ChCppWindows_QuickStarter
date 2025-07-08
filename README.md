### 概要

このProjectは`ChCppLibrary`のサンプルとして組み上げたものです。
利用しているライブラリは以下のものになります。

- [ChCppBaseLibrary](https://github.com/Chronoss0518/ChCppBaseLibrary)
- [ChCppWinLibrary](https://github.com/Chronoss0518/ChCppWinLibrary)

### 切り替え方法

main.cppにある以下の`#if`または`#elif`の0と1を切り替えることで、内容が切り替わるようになっています。

```C++

#if 0 //←切り替えられる場所//
    // Windowの作り方
    CreateApplicationWindow
#elif 0 //←切り替えられる場所//
    // Bitmap画像のロード及び表示
    DrawImage
#elif 0 //←切り替えられる場所//
    // MessageBoxの表示
    DrawMessageBox
#elif 0 //←切り替えられる場所//
    // Buttonの作成および表示
    DrawButton
#elif 1 //←切り替えられる場所//
    // FileDialogの表示
    DrawFileDialog
#endif

```

サンプルコードは以下の通りです。

- [CreateWindow](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/CreateWindow)
  - WindowsのWindowを表示するためのSampleです
- [DrawImage](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawImage)
  - Bitmapを画面上に表示するSampleです
- [DrawMessageBox](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawMessageBox)
  - MessageBoxを表示するためのSampleです
- [DrawButton](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawButton)
  - Buttonを表示し押下した際にMessageBoxを表示するSampleです
- [DrawFileDialog](https://github.com/Chronoss0518/ChCppWindows_QuickStarter/tree/master/src/DrawFileDialog)
  - Fileを選択するためのDialogを表示し、選択したファイルの絶対パスをMessageBoxで表示するためのSampleです