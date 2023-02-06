writefile=$1
writestr=$2

dr=$(dirname $writefile)

if [ $# -lt 2 ] ; then
    if [ $# == 0 ] ; then
        echo " missing writefile and writestr"
    fi
    if [ $# == 1 ] ; then
        echo " missing writestr"
    fi
    exit 1
fi

if [ ! -d $(dirname $writefile) ]; then
    mkdir -p $dr
fi

if ! echo $writestr > $writefile; then
    echo error
    exit 1
fi
