# CRCLTR

Looper firmware for Noise Engineering Versio eurorack module. Check the <a href="https://github.com/s3g/crcltr/releases">Releases page for latest bin file</a>.  Use the <a href="https://electro-smith.github.io/Programmer/">Daisy Web Programmer</a> to upload to your Versio module.

<img src="https://github.com/s3g/crcltr/assets/2341558/8543cadd-4c53-4c67-aff7-c281ff58f9c5" width="360">

**Overview**
------------

CRCLTR (a.k.a. circulator or circle later) is stereo looper firmware for Noise Engineering's <a href="https://noiseengineering.us/pages/world-of-versio">Versio eurorack module</a> which uses the <a href="https://electro-smith.com/">Daisy Seed</a> embedded computing platform. It is made with the *Max* &rarr; *Gen* &rarr; *Oopsy* workflow.  The bin file is available on the releases page for this repo, for installation with the <a href="https://electro-smith.github.io/Programmer/">Daisy Web Programmer</a> onto your Versio module.  In order to use the source code (i.e. Max patches), you will need the <a href="https://cycling74.com">Max programming environment</a> with the <a href="https://github.com/electro-smith/oopsy">Oopsy package</a> installed.  



**Parameters**
--------------

Here are the mappings using the Antri Versio faceplate numbering:

* 1: Loop 1 rate: adjust playback speed, 11 o'clock is 1x, range 0.25 - 2.75
* 2: Loop 2 rate: adjust playback speed, 11 o'clock is 1x, range 0.25 - 2.75
* 3: Xfade type: manual, sin LFO, or trapezoid LFO
* 4: Xfade control, loop 1 vs. loop 2: position for manual mode, rate for LFO modes 
* 5: Blend: mix between audio source and the recorded loops
* 6: Input gain: hot signals will get some tanh distortion
* 7: Output gain:: hot signals will get some tanh distortion
* FSU / button / gate: record loop while held 
* Switch 1 (top): set which loop to record to, left = loop 1, right = loop 2, middle both
* Switch 2 (bottom): set pass thru while recording, left/right = thru, middle = silent


**Tips and notes for v.1.0.1**
------------------------------

**Loop 1** creates a seamless loop by crossfading two sample players using the first half of audio recorded.  Therefore the record button/gate must be held for twice the duration of the intended loop.  So for a 2-second loop, the button/gate must be held for 4 seconds.  The maximum loop duration is 16 seconds.

**Loop 2** creates a full duration loop with volume ducking at the start/end points to avoid clicks or obvious glitches.  The duck time is set to 250 milliseconds.  The maximum loop duration is 32 seconds.

**Xfade type** is assigned by setting the dial to the left (manual), middle (sin LFO), or right (trapezoid LFO).

**Xfade** control in manual mode moves between loop 1 (left) and loop 2 (right) using equal power fading.  The Xfade control in LFO modes changes the rate of LFO from slow (left) to fast (right).  The baseline LFO rate stems from loop 1's rate multiplied by 0.25 (left) to 4 (right).

**Record switch** (top, switch 1) allows for both loops to be recorded simultaneously (middle) or individually (left loop 1, right loop 2).

**Thru switch** (bottom, switch 2) allows the source audio to be heard while recording in the left and right positions or not in the middle position.  The choice between "thru 1" and "thru 2" allows the pass thru to be relative to the Xfade type and position.  This way it is possible to hear the opposite loop combined with the source audio while recording.  

**Blend** mixes between the source audio and recorded loops with equal power.

**Gain dials** for input and output can be set near 4 o'clock for good results. It will depend somewhat on your patch signals where you want this.  If either is a hot signal, tanh distortion is applied.  

**FSU / button / gate** records while held.  This ignores button/gate times less than 100 milliseconds to avoid accidental loop erasures. 

**Why these decisions?** That's the great thing about making your own firmware. I've customized this module to work well with my system and performance approach.  There was a lot of trial and error to see what translates well to the Versio module while I was learning more about Gen programming in Max. No doubt there is room for improvement and optimization of the code.  

**Suggestion.** If you have two Versio modules, install this firmware on both and use in tandem, feeding one into the other.  That way you could have double seamless loopers (loop 1) or double ducking loopers (loop 2), use all four loopers together, or makes loops out of loops. Try setting the Xfade type to an LFO mode on both modules and the Blend dial around 12 o'clock on the second module and you'll have all 4 loops interacting. 






