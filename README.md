# OneStudentOneChip

One Student One Chip (YSYX) is started by University of Chinese Academy of Sciences (UCAS) and Institution of Computing Technology (ICT) of Chinese Academy of Sciences (CAS) with other research agencies and companies. The purpose of this project is to let every student get their own RISC-V chip back on silicon.

“一生一芯”计划是由中国科学院大学（UCAS）和中国科学院计算技术研究所（ICT-CAS）以及其他的研究机构和企业共同发起的项目。其目的是让学生设计出自己的RISC-V芯片并进行流片。

I am Yan Yusong (Jason), a student from Beijing No. 101 High School, I am enrolling in this project, and this GitHub repo is for storing my code and tracing my course works.（Recently, I created 4 GitHub repositories to store my code for each phase of this project[Preview](https://github.com/Jasonyanyusong/ysyx_Preview)[Basic](https://github.com/Jasonyanyusong/ysyx_Basic)[Advanced](https://github.com/Jasonyanyusong/ysyx_Advanced)[Super](https://github.com/Jasonyanyusong/ysyx_Super)）

我是烟雨松（一生一芯学号ysyx_22041384），来自北京一零一中学（高中国际部&英才学院），正在“一生一芯”项目中进行学习，本GitHub仓库将记录我的项目代码变化。（近期创建了4个GitHub仓库，用于一生一芯每个阶段的代码打包保存[预学习](https://github.com/Jasonyanyusong/ysyx_Preview)[基础](https://github.com/Jasonyanyusong/ysyx_Basic)[进阶](https://github.com/Jasonyanyusong/ysyx_Advanced)[专家](https://github.com/Jasonyanyusong/ysyx_Super)）

Progress report: (Chinese Chart)

* 注：1、学习阶段相关任务类型：C/++（C/C++语言相关学习）V（Verilog/Verilator/IVerilog相关学习）G（GTKWave相关学习）S（计算机组成原理相关学习）D（数字电路相关学习）A（模拟电路相关学习）L（Linux/相关工具学习）N（科学方法/素养）2、部分内容跟我我的个人代码仓库git log记录并生成

|日期|任务类型|计划任务|总时长|任务完成情况|卡了一段时间的bug|备注|记录故事/心情|
|----|----|----|----|----|----|----|----|
|2022/11/21|L|重新配置Ubuntu Linux开发环境，并部署相关工具（APT源相关工具）|2h|大致完成了任务，并且写出了[实验报告](https://docs.qq.com/doc/DSVplS2dNRWVxUXZG)|NEMU在ARM处理器的Ubuntu Linux中无法正常的运行，会出现core dump的问题（此问题后期我会在x86-64）的Ubuntu Linux中再次尝试，若x86的系统中可运行，则有可能是兼容性问题，后期会反馈。|ARM的Ubuntu系统是在基于M1的Mac上开的虚拟机，但是其他工具都能够正常工作|个人现在感觉还是x86平台进行开发比较靠谱，我的Mac经常会有一些工具不兼容或者效率低，但是应该可以通过优化等方式进行解决|
|2022/11/22|L/N|熟悉Git操作，并在GitHub中给一生一芯项目建立独立的代码仓库（或者根据要求，在给定的代码仓库中进行tracing）|2h|通过克隆ysyx- workbench和其他工具，并在GitHub上面开通了自己的代码仓库，并且对PA0中的Git部分实验再次进行了巩固，Git使用目前较为熟悉| GitHub由于一些原因，访问较慢，需要配置代理或者使用镜像站或者使用GitLab自建代码仓库（目前有一台云服务器）|已经解决问题，使用github继续保存代码|虽然使用Git追踪开发进度是一件非常繁琐和复杂的事情（需要在意很多的细节并比直接保存代码麻烦好多）但是Git可以让开发项目的团队在某个版本出现问题后快速的回滚到上一个可用版本，增加了工程的可用性。同时使用Git可以保证代码的原创性，从而促进学习进度和学习动机。|
|2022/11/23|N|阅读“提问的智慧”和“别像弱智一样提问”并编写阅读报告|2h|完成了阅读任务，并编写了1000字以上的[读后感](https://docs.qq.com/doc/DSUFTakJuWnV3bmNT)|阅读任务没有上机操作，不进行记录|阅读报告链接在任务完成情况中|重新认识了科学研究的过程，以后进行科学提问需要经过思考，不能够发现什么问题直接提出来，提出问题之后也要不停思考原来的问题。通过交流合作提升项目进度。|
|2022/11/24|N/A/D|阅读《模拟电路与数字电路》第1章（绪论）；第2章（半导体器件基础）；第8章（数字逻辑基础）|6h|完成了阅读，编写了[学习记录](https://docs.qq.com/doc/DSVFORXZLZ0x3WGJJ)| | | |
|2022/11/26|V/G|完成了二选一选择器设计（框架）|2h|完成了二选一选择器设计（框架）| | | |
|2022/11/27|V/G|完成了二选一选择器设计（数据流建模、结构建模、行为建模）|2h|完成了三个方法建模二选一选择器，并使用verilator相关功能进行编译，并通过gtkwave查看波形图| | | |
|2022/11/28|V/G|完成了四选一选择器设计|2h|使用case方法设计了四选一选择器，并自己编写了仿真激励文件| | | |