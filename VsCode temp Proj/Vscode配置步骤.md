# Vscode 编译 C 配置步骤

------

## 环境配置

1.  先安装和配置“mingw-w64”编译器工具链，到 [这里](https://sourceforge.net/projects/mingw-w64/files/) 下载 “x86_64-posix-sjlj” 版本的 “mingw-w64” ，解压到任意路径比如 “D:\\mingw64\\bin\\”。
2.  然后添加环境变量的“Path”，让系统 cmd 在任意位置能够运行 gcc -v 等命令，即算成功。具体：系统属性 -> 高级系统设置 -> 环境变量 -> 系统变量，找到 Path，编辑添加一项“D:\mingw64\bin\”即可。

## 建立VsCode工程

新建一个文件夹当作工程文件夹，添加程序文件，然后在当前目录右击鼠标，选用VsCode打开（或则先打开VsCode再打开此目录）。工程路径不能有中文。

### 单文件快速编译运行

此方法只对单文件（没有调用工程文件夹内其他用户文件）快速看个结果有效。

安装插件 “Code Runner”，然后然后依次打开：文件>首选项>设置>用户>拓展>Run Code Configuration，找到**`Run In Terminal`**勾选上。然后在VsCode里面点开一个c程序文件，在右上角有一个箭头符号，是Code Runner的运行按钮，会在控制台显示程序输出信息。点控制台右上角的垃圾箱图标为停止运行。

### 正经 C 调试

#### 快速运行

1.  在VsCode里面点 “运行->“添加配置”，添加一个gdb.exe配置，就会出现名为“.vscode”文件夹和里面的“launch.json”和"task.json"两个文件。
2.  这时程序就会编译跑起来。默认程序在控制台输出信息，可以修改“launch.json”文件里的"externalConsole"为 true 即使用运行程序与新控制台窗口。
3.  还可以加断点进行单步调试。

#### 正经的配置文件

简易C编译模板：“.vscode”里面的配置文件直接复制“VsCode temp Proj.zip”里面的。

有关C++的详看 [这里](https://blog.csdn.net/lyw851230/article/details/89352839)

## 其他可选扩展

-   [嵌入式应用中所使用的vscode 插件](https://www.zcxbb.com/index.php/2021/03/24/嵌入式应用中所使用的vscode-插件/)

    \1. ARM :识别arm 汇编语言
    \2. Auto Comment Blocks :自动注释
    \3. Beautify ：美化花括号
    \4. Binary :二进制文件预览
    \5. Bracket Pair Colorizer ：括号颜色
    \6. C/C++
    \7. C/C++ Snippets
    \8. C++ Intellisense
    \9. Chinese (Simplified) Language Pack for Visual Studio Code
    \10. cmake
    \11. DeviceTree
    \12. Include Autocomplete
    \13. LinkerScript
    \14. Python
    \15. TSLint
    \16. vscode-icons

-   Bracket Pair Colorizer：彩虹花括号

-   Include Autocomplete：提供头文件名字的补全，不过用处不大；而且其实现在cpptools已经自带这个功能了，但本文不使用它的补全

-   C/C++ Snippets：Snippets即重用代码块，效果自己百度；这个扩展安装量虽高，不过个人感觉用处实在不大，你也可以选择其他的Snippets扩展甚至自己定义

-   One Dark Pro：大概是VS Code安装量最高的主题

-   vscode-clangd：这个和Adapter二选一，出得比Adapter晚，下载量也低，但却是llvm官方出的。出现问题时可以换着试试

-   Clang-Format：只有想自定义代码风格时才装，比如大括号不换行。需要另外学习如何使用

-   [10款VS Code插件神器，第7款超级实用！](https://mp.weixin.qq.com/s/E3Emku5IW9p8VlM1BiVC8Q)