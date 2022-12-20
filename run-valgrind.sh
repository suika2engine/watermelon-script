#!/bin/sh

set -eu

for f in testcases/*.scr; do
    echo "Running $f ..."
    valgrind --leak-check=full --error-exitcode=1 ./wms $f
done

echo 'All tests are passed!'
