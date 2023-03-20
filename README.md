# OneStudentOneChip

One Student One Chip (YSYX) is started by University of Chinese Academy of Sciences (UCAS) and Institution of Computing Technology (ICT) of Chinese Academy of Sciences (CAS) with other research agencies and companies. The purpose of this project is to let every student get their own RISC-V chip back on silicon.

“一生一芯”计划是由中国科学院大学（UCAS）和中国科学院计算技术研究所（ICT-CAS）以及其他的研究机构和企业共同发起的项目。其目的是让学生设计出自己的RISC-V芯片并进行流片。

I am Yan Yusong (Jason), a student from Beijing No. 101 High School, I am enrolling in this project, and this GitHub repo is for storing my code and tracing my course works.（Recently, I created 4 GitHub repositories to store my code for each phase of this project[Preview](https://github.com/Jasonyanyusong/ysyx_Preview); [Basic](https://github.com/Jasonyanyusong/ysyx_Basic); [Advanced](https://github.com/Jasonyanyusong/ysyx_Advanced); [Super](https://github.com/Jasonyanyusong/ysyx_Super)）

我是烟雨松（一生一芯学号ysyx_22041384），来自北京一零一中学（高中国际部&英才学院），正在“一生一芯”项目中进行学习，本GitHub仓库将记录我的项目代码变化。（近期创建了4个GitHub仓库，用于一生一芯每个阶段的代码打包保存[预学习](https://github.com/Jasonyanyusong/ysyx_Preview); [基础](https://github.com/Jasonyanyusong/ysyx_Basic); [进阶](https://github.com/Jasonyanyusong/ysyx_Advanced); [专家](https://github.com/Jasonyanyusong/ysyx_Super)）

* 文件结构:
* * .vscode/ -> 编辑工具Visual Studio Code的相关配置
* * DigitalCircuitsExperiments/ -> 南京大学[《数字电路基础实验》](https://nju-projectn.github.io/dlco-lecture-note/index.html)
* * LabReport/ -> 数字电路基础实验和PA实验以及后期其他实验的实验报告
* * npc/ -> New Processor Core (新处理器核)
* * pa0/ -> 南京大学计算机系统基础课程实验 PA0的相关代码保存
* * pa1/ -> 南京大学计算机系统基础课程实验 PA1的相关代码保存
* * * nemu_run -> 用于编译运行的NEMU（实现简易调试器、表达式求值、监视点）
* * * nemu_new -> 用于调试运行的NEMU（实现简易调试器、表达式求值、监视点），支持打印各种程序运行中的调试信息
* * pa2/ -> 南京大学计算机系统基础课程实验 PA2的相关代码保存
* * * nemu_run -> 用于编译运行的NEMU（基于PA1的NEMU）
* * * nemu_dev -> 用于调试运行的NEMU（基于PA1的NEMU），支持打印各种程序运行中的调试信息
* * pa3/ -> 南京大学计算机系统基础课程实验 PA3的相关代码保存
* * pa4/ -> 南京大学计算机系统基础课程实验 PA4的相关代码保存
* * PreLearnActivities/ -> “一生一芯”讲义中，预学习部分的编程活动
* * ProgressReport/ -> 用于记录进展，记录实验日志
* * resources/ -> 一些实验的资源
* * * nes/ -> 模拟红白机的一些游戏（通过STFW获得）
* * tools/ -> 一些“一生一芯”学习过程中手动创建的工具，可以加速实验进度
* * * gate_tools/ -> Verilog HDL写好的门电路
* * * testbench_tools/ -> 使用Python实现的数字电路中，自动生成测试数据的脚本
* * ustc_verilogoj/ -> 中国科技大学的Verilog OJ练习题以及我的答案

* 联系方式：
* * 微信：jasonyanys（请备注来意）
* * 邮箱：jasonyanyusong@outlook.com

* Progress report: (Chinese Chart)

* * 注1：学习阶段相关任务类型：C/++（C/C++语言相关学习）V（Verilog/Verilator/IVerilog相关学习）G（GTKWave相关学习）S（计算机组成原理相关学习）D（数字电路相关学习）A（模拟电路相关学习）L（Linux/相关工具学习）N（科学方法/素养）
* * 注2：部分内容跟我我的个人代码仓库git log记录并生成

|日期|任务类型|计划任务|总时长|任务完成情况|卡了一段时间的bug|备注|记录故事/心情|
|----|----|----|----|----|----|----|----|
|2022/11/21|L|重新配置Ubuntu Linux开发环境，并部署相关工具（APT源相关工具）|2h|大致完成了任务，并且写出了[实验报告](https://docs.qq.com/doc/DSVplS2dNRWVxUXZG)|NEMU在ARM处理器的Ubuntu Linux中无法正常的运行，会出现core dump的问题（此问题后期我会在x86-64）的Ubuntu Linux中再次尝试，若x86的系统中可运行，则有可能是兼容性问题，后期会反馈。|ARM的Ubuntu系统是在基于M1的Mac上开的虚拟机，但是其他工具都能够正常工作|个人现在感觉还是x86平台进行开发比较靠谱，我的Mac经常会有一些工具不兼容或者效率低，但是应该可以通过优化等方式进行解决|
|2022/11/22|L/N|熟悉Git操作，并在GitHub中给一生一芯项目建立独立的代码仓库（或者根据要求，在给定的代码仓库中进行tracing）|2h|通过克隆ysyx- workbench和其他工具，并在GitHub上面开通了自己的代码仓库，并且对PA0中的Git部分实验再次进行了巩固，Git使用目前较为熟悉| GitHub由于一些原因，访问较慢，需要配置代理或者使用镜像站或者使用GitLab自建代码仓库（目前有一台云服务器）|已经解决问题，使用github继续保存代码|虽然使用Git追踪开发进度是一件非常繁琐和复杂的事情（需要在意很多的细节并比直接保存代码麻烦好多）但是Git可以让开发项目的团队在某个版本出现问题后快速的回滚到上一个可用版本，增加了工程的可用性。同时使用Git可以保证代码的原创性，从而促进学习进度和学习动机。|
|2022/11/23|N|阅读“提问的智慧”和“别像弱智一样提问”并编写阅读报告|2h|完成了阅读任务，并编写了1000字以上的[读后感](https://docs.qq.com/doc/DSUFTakJuWnV3bmNT)|阅读任务没有上机操作，不进行记录|阅读报告链接在任务完成情况中|重新认识了科学研究的过程，以后进行科学提问需要经过思考，不能够发现什么问题直接提出来，提出问题之后也要不停思考原来的问题。通过交流合作提升项目进度。|
|2022/11/24|N/A/D|阅读《模拟电路与数字电路》第1章（绪论）；第2章（半导体器件基础）；第8章（数字逻辑基础）|6h|完成了阅读，编写了[学习记录](https://docs.qq.com/doc/DSVFORXZLZ0x3WGJJ)| | | |
|2022/11/26|V/G|完成了二选一选择器设计（框架）|2h|完成了二选一选择器设计（框架）| | | |
|2022/11/27|V/G|完成了二选一选择器设计（数据流建模、结构建模、行为建模）|2h|完成了三个方法建模二选一选择器，并使用verilator相关功能进行编译，并通过gtkwave查看波形图| | | |
|2022/11/28|V/G|完成了四选一选择器设计|2h|使用case方法设计了四选一选择器，并自己编写了仿真激励文件| | | |
|2022/12/8|V/G|完成编码器、译码器|2h|任务已经完成，编码器和译码器分别设计了case方法和for方法进行建模。| | | |
|2022/12/9|V/G|七段数码管驱动模块的设计|2h|完成了共阳极和共阴极七段数码管的驱动模块设计，并使用波形图查看仿真结果| | | |
|2022/12/10|V/G|全加器设计|2h|完成了一位全加器设计，并将其串联成四位的版本，通过数据流建模设计加法计算功能模块| | | |
|2022/12/13|V/G|设计加减法运算器与ALU|2h|完成了设计，并编写了仿真测试文件| | | |
|2022/12/14|V/G|设计加减法运算器与ALU|2h|设计了更多的测试用例进行测试模块正确性| | | |
|2022/12/17|V/G|设计加减法运算器与ALU|2h|继续增加测试样例| | | |
|2022/12/19|V/G|整理总结完成数字电路基础实验4|2h|debug| | | |
|2023/1/1|V/G|寄存器的学习|2h|完成了一位寄存器和多位寄存器的设计，并且通过了Verilator进行仿真测试，掌握了一些时序逻辑电路的设计方法| | | |
|2023/1/7|V/G|加法计数器、减法计数器|2h|设计了多种加法计数器和减法计数器，并通过verilator进行仿真，通过gtkwave进行结果检验| | | |
|2023/1/8|V/G|加法计数器、减法计数器|2h|设计了多种加法计数器和减法计数器，并通过verilator进行仿真，通过gtkwave进行结果检验| | | |
|2023/1/9|V/G|桶形移位寄存器|2h|阅读了8位桶形移位寄存器的设计图，并通过Verilog结构化建模实现了这个模块| | | |
|2023/1/11|V/G|桶形移位寄存器|2h|阅读了8位桶形移位寄存器的设计图，并通过Verilog结构化建模实现了这个模块| | | |
|2023/1/14|环境|设计了自动安装相关环境依赖的脚本|2h|因为我电脑设备来回换，懒得敲太多命令行，整了一个这个| | | |
|2023/1/17|V/G|循环移位设计|2h|设计了正跳变沿河负跳变沿的循环左移位寄存器和循环右移位寄存器| | | |
|2023/1/18|V/G|算数移位设计+逻辑移位设计|2h|设计了正跳变沿河负跳变沿的算数左移位寄存器和算数右移位寄存器，设计了正跳变沿河负跳变沿的逻辑左移位寄存器和逻辑右移位寄存器| | | |
|2023/1/24|V/G|阅读数字电路基础实验7讲义|2h|完成阅读，学习了有限状态机的定义| | | |
|2023/1/25|V/G|FSM设计|2h|理解了有限状态机的工作原理，并完成了一个检测四个连续相同输入的有限状态机| | | |
|2023/1/26|V/G|PS/2设计|2h|阅读了有关PS/2相关的讲义，并编写仿真文件仿真了键盘F1-F2的按键| | | |
|2023/1/30|C/L|NEMU|2h|修改了一进入就出发assertion的bug；让其可以实现优雅的退出；添加了w、si、info r功能| | | |
|2023/1/31|C/L|NEMU|2h|添加了x功能| | | |