#!/bin/sh

set -eu

for f in testcases/*.scr; do
    echo -n "Running $f ... "
    ./wms $f > out
    diff $f.out out
    rm out
    echo "passed."
done

echo 'All tests are passed!'
