filesdir=$1
searchstr=$2

if [ ! -d $filesdir ]; then
    echo $filesdir is not a directory
    exit 1
fi

if [ $# -lt 2 ] ; then
    if [ $# == 0 ] ; then
        echo missing filesdir and searchstr
    fi
    if [ $# == 1 ] ; then
        echo missing searchstr
    fi
    exit 1
fi

echo The number of files are $(find $filesdir -type f | wc -l) and the number of matching lines are $(find $filesdir -type f | xargs grep $searchstr | wc -l)
