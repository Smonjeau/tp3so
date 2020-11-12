#!/bin/bash
server/server &
sleep 1
./run_client_from_outside.sh