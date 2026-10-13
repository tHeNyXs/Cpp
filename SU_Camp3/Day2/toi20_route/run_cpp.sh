#!/bin/bash

problem="route"
memory=524288  # 2GB
stack_size=524288  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
