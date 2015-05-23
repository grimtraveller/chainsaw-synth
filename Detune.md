# Introduction #

The detune parameter detunes both of the [oscillators](Oscillator.md) in the oscillator group, one of the oscillators is tuned up the other down. As oscillator group 1 has only single oscillator, no detuning will be applied to that one.


## The detuning algorithm ##

Oscillators are detuned according to following algorithm. Detune amount is given in semitones, where _da_ is the amount of detuning set by the plugin parameters.

| Oscillator group | Detune amount | Left direction | Right Direction |
|:-----------------|:--------------|:---------------|:----------------|
| 1                | none          | n/a            | n/a             |
| 2                | _da_ x 0.3    | down           | up              |
| 3                | _da_ x 0.6    | up             | down            |
| 4                | _da_ x 0.9    | down           | up              |