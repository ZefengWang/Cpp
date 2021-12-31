# set some global variables
CONDA_PKG='Miniconda3-py38_4.10.3-Linux-x86_64'
SOURCE_URL='https://mirrors.tuna.tsinghua.edu.cn'
TEMP_PATH="$HOME/.anaconda_tmp"
PROXY_ADDR='127.0.0.1'
PROXY_PORT='1080'
QIIME2="qiime2-2021.11-py38-linux-conda"

# save orignal path
RAWPATH=`pwd`

# create a new path for store temp files
mkdir -p $TEMP_PATH

# change directory
cd $TEMP_PATH

# download miniconda script
wget -c $SOURCE_URL/anaconda/miniconda/$CONDA_PKG.sh  && { echo "download error!"; exit 1 }

# install Miniconda, this way is same as `bash Miniconda3-py38_4.10.3-Linux-x86_64.sh` but not every linux distributes has bash expecially for very old distributes
chmod +x $CONDA_PKG.sh
./$CONDA_PKG.sh && { echo "execute scripts failed!"; exit 1 }

# update .bashrc in current sessions, source command is same as . command
. ~/.bashrc

# change source list for conda
echo << EOF > ~/.bashrc
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
conda clean -i && { echo "clean index caches error"; exit 1 }

# download yml file
proxy_https="https://$PROXY_ADDR:$PROXY_PORT" wget "https://data.qiime2.org/distro/core/$QIIME2.yml"
if [ ! $? == 0 ]; then echo "please set global proxy ip and port"; exit 1;fi

# edit qiime2 labels
sed -i "2cqiime2" $QIIME2.yml

# create env
conda env create -n qiime2-2021.11 --file $QIIME2.yml && {  echo "create qiime env failed"; exit 1 }

# active qiime2
conda activate qiime2-2021.11

# test qiime2
qiime --help

# quit qiime env
conda deactivate qiime2-2021.11

# go back to raw path
cd $RAWPATH
