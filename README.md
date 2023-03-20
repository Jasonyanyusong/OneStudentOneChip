# OneStudentOneChip

One Student One Chip (YSYX) is started by University of Chinese Academy of Sciences (UCAS) and Institution of Computing Technology (ICT) of Chinese Academy of Sciences (CAS) with other research agencies and companies. The purpose of this project is to let every student get their own RISC-V chip back on silicon.

I am Yan Yusong (Jason), a student from Beijing No. 101 High School, I am enrolling in this project, and this GitHub repo is for storing my code and tracing my course works.

Progress report: (Chinese Chart)

|日期|任务类型|计划任务|总时长|任务完成情况|卡了一段时间的bug|备注|记录故事/心情|
|2022/11/21|L|重新配置Ubuntu Linux开发环境，并部署相关工具（APT源相关工具）|2h|大致完成了任务，并且写出了实验报告[链接](https://docs.qq.com/doc/DSUFTakJuWnV3bmNT)|NEMU在ARM处理器的Ubuntu Linux中无法正常的运行，会出现core dump的问题（此问题后期我会在x86-64）的Ubuntu Linux中再次尝试，若x86的系统中可运行，则有可能是兼容性问题，后期会反馈。|ARM的Ubuntu系统是在基于M1的Mac上开的虚拟机，但是其他工具都能够正常工作|个人现在感觉还是x86平台进行开发比较靠谱，我的Mac经常会有一些工具不兼容或者效率低，但是应该可以通过优化等方式进行解决|
|2022/11/22|L/N|熟悉Git操作，并在GitHub中给一生一芯项目建立独立的代码仓库（或者根据要求，在给定的代码仓库中进行tracing）|2h|通过克隆ysyx- workbench和其他工具，并在GitHub上面开通了自己的代码仓库，并且对PA0中的Git部分实验再次进行了巩固，Git使用目前较为熟悉| GitHub由于一些原因，访问较慢，需要配置代理或者使用镜像站或者使用GitLab自建代码仓库（目前有一台云服务器）|已经解决问题，使用github继续保存代码|虽然使用Git追踪开发进度是一件非常繁琐和复杂的事情（需要在意很多的细节并比直接保存代码麻烦好多）但是Git可以让开发项目的团队在某个版本出现问题后快速的回滚到上一个可用版本，增加了工程的可用性。同时使用Git可以保证代码的原创性，从而促进学习进度和学习动机。|
