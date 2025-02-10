#!/bin/bash

# Check if VLC is already running
if pgrep -x "vlc" > /dev/null
then
    echo "VLC is already playing music."
else
    # Start VLC to play music in the background
    vlc --intf dummy /home/aingunza/Downloads/LofiDBZ.mp3 &
    VLC_PID=$!
    echo "Starting music..."

    # Trap the exit signal (Ctrl+C or terminal close)
    trap "kill $VLC_PID" EXIT

    # Wait for the VLC process to finish (this keeps the script running)
    wait $VLC_PID
fi