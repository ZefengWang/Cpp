#!/bin/bash

# 函数用来处理每个小文件
# 也可以用shell命令来处理
# 使用curl,awk,grep,sed等命令组合
# 但是会比较麻烦，所以用python脚本处理
function get_files()
{
	#python3 your_file_to_processing $1
}

# 把包含zip文件的目录以参数形式传递进来
if [ -z $1 ]
then
	echo "usage: $0 [dir]\n\tdir contains zip files\n"
	exit 0
fi

# 时间字符串用来保存路径名用来调试
for_debug=`date +"%Y-%m-%d-%H-%M-%S"`
echo "cur time is: $for_debug"

# 将zip文件名保存到一个文件里
ls $1 > $for_debug.txt

# 创建一个目录用来保存文件名
if [ ! -d $for_debug ]
then
	mkdir "${for_debug}"
fi

# 将大文件拆分小文件
split  --number=l/`nproc` -d $for_debug.txt $for_debug/thread-
echo "split done"

for file in $for_debug
do
	# 后面加 &号表示后台进行
	get_files $for_debug/$file &
done

# 等待所有任务运行完毕
wait
echo "all tasks done"
