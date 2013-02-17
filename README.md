# Vitamine

Basic virtual machine that aims to implement hot-code swapping primitives *a la Erlang*.
Project realized within the framework of the SUPINFO Low-Level Laboratory - SL3.

## Usage : 

```
% mkdir bin && cd bin
% cmake ..
% ./src/vitamine ../test/basic-arithmetic.s
42

% ./src/vitamine ../test/counter.s
1
2
3
[...]
999999
1000000
```

## History :

* 2013-02-17 : Added control flow (jmp, je, jne)
* 2013-02-11 : Support basic arithmetics operations available in test/basic-arithmetic.s.

## Authors :

* Timothée "mitknil" Bernard &lt;bernard.timothee@gmail.com&gt;
* Arnaud Barisain-Monrose
