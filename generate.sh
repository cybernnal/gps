#!/usr/bin/env bash
./push_swap -m `ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`
