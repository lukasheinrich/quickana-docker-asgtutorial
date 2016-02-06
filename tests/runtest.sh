#!/bin/bash
source /analysis/setup.sh
curl -O http://physics.nyu.edu/~lh1132/test_ttbar_AOD.pool.root 
ROOTCORE_TEST_FILE=$PWD/test_ttbar_AOD.pool.root athena.py $TestArea/MyAnalysis/share/MyJobOptions.py
