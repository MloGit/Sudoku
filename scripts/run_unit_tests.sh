#!/bin/bash

cd "$(dirname "$0")" # Set cwd to /scripts
cd ../tests/

ceedling test:all < test/player_input_for_tests.txt