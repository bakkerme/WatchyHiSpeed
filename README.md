# HiSpeed watchface for Watchy
A sleek, modern watchface watchface for the Watchy platform.

Features time, date, temperature and step count and battery. Weather hasn't been integrated.

Battery is the line that splits up the seperator blocks. It's only implemented in 30% intervals right now.

![Example Image](/design/photo.jpg)

## Settings
In `Watchy_hispeed.cpp`, DARKMODE can be toggled on or off, depending on your preferences. By default it's switched on.
There are also a few different types of sperators implemented in the code, including the default block with battery meter, an angled version and a simple line.

The clock uses 12 hour time by default. If you'd like to use 24 hour time, remove the `% 12` in the `drawTime` function.

## Design
In the design folder, the base designs I built the watchface off can be found, including the required fonts. The design is an inkscape svg. You'll need to install the Squared Display font to use it. The Squared Display Monospace font is not used in the design, it's a modification I made to help me make the layouts more to my taste. It's only used in the watch face.

Note that the designs aren't completely accurate to the final face, they're just guides.

Font is [Squared Display by Vikas Kumar.](https://www.dafont.com/squared-display.font)