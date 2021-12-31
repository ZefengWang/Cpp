# LGPL
# copy-left
# I am an open source suppourter
# but this file is just help zimu, not need to obey LGPL in this repo

function zimu()
{
	# set some local variables
	CONDA_PKG='Miniconda3-py38_4.10.3-Linux-x86_64'
	SOURCE_URL='https://mirrors.tuna.tsinghua.edu.cn'
	TEMP_PATH="$HOME/.anaconda_tmp"
	MINICONDA="$HOME/miniconda3"
	QIIME2="qiime2-2021.11-py38-linux-conda"
	
	# get ip address from https://ipaddress.com which domain name we need is raw.githubusercontent.com
	GITHUB_ADDR="185.199.108.133"
	COMMADN="$GITHUB_ADDR raw.githubusercontent.com"
	
	# save orignal path
	RAWPATH=`pwd`

	# edit hosts for github
	grep "raw.githubusercontent.com" /etc/hosts
	if [ $? == 1 ]; then sudo bash -c "echo $GITHUB_ADDR raw.githubusercontent.com >> /etc/hosts"; fi

	# check if first install, if not remove them
	if [ -d $TEMP_PATH ]; then rm -rf $TEMP_PATH; fi
	if [ -d $MINICONDA ]; then rm -rf $MINICONDA; fi

	# create a new path for store temp files
	mkdir -p $TEMP_PATH

	# change directory
	cd $TEMP_PATH

	# download miniconda script
	wget -c "$SOURCE_URL/anaconda/miniconda/$CONDA_PKG.sh"  || { echo "download error!"; return 1; }

	# install Miniconda, this way is same as `bash Miniconda3-py38_4.10.3-Linux-x86_64.sh` but not every linux distributes has bash expecially for very old distributes
	chmod +x $CONDA_PKG.sh
	./$CONDA_PKG.sh || { echo "execute scripts failed!"; return 1; }

	# update .bashrc in current sessions, source command is same as . command
	source ~/.bashrc

	# change source list for conda
	cat << EOF > ~/.condarc
channels:
  - defaults
show_channel_urls: true
default_channels:
  - $SOURCE_URL/anaconda/pkgs/main
  - $SOURCE_URL/anaconda/pkgs/r
  - $SOURCE_URL/anaconda/pkgs/msys2
custom_channels:
  conda-forge: $SOURCE_URL/anaconda/cloud
  msys2: $SOURCE_URL/anaconda/cloud
  bioconda: $SOURCE_URL/anaconda/cloud
  menpo: $SOURCE_URL/anaconda/cloud
  pytorch: $SOURCE_URL/anaconda/cloud
  pytorch-lts: $SOURCE_URL/anaconda/cloud
  simpleitk: $SOURCE_URL/anaconda/cloud
  qiime2: $SOURCE_URL/anaconda/cloud
EOF

	# clean index caches for conda
	conda clean -i || { echo "clean index caches error"; return 1; }

	# download yml file
	wget "https://data.qiime2.org/distro/core/$QIIME2.yml"
	if [ ! $? == 0 ]; then echo "please set global proxy ip and port"; return 1;fi

	# edit qiime2 labels
	sed -i "2c\ \ -\ qiime2" $QIIME2.yml

	# create env
	conda env create -n qiime2-2021.11 --file $QIIME2.yml || {  echo "create qiime env failed"; return 1; }

	echo "done"
	# go back to raw path
	cd $RAWPATH
}

zimu
