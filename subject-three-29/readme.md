## Задача 29. Пересечение реки

| параметр  | значения  |
|---|---|
| Имя входного файла:     | input.txt     |
| Имя выходного файла:    | output.txt    |
| Ограничение по времени: | 1c            |
| Ограничение по памяти:  | нет           |

## Условие

На реке имеется <span style="white-space: nowrap">_n_</span> островков, пронумерованных от 1 до <span style="white-space: nowrap">_n_</span> слева направо поперёк реки. Жители должны пересечь реку, начиная с её левого берега, используя некоторые островки, для достижения правого берега. Левый берег расположен на одну позицию левее первого островка, а правый берег расположен на одну позицию правее островка с номером <span style="white-space: nowrap">_n_</span>. В момент времени <span style="white-space: nowrap">_t_=0</span> житель находится на левом берегу реки и имеет целью добраться до правого берега за минимальное время. В каждый момент времени каждый из островков поднят или опущен и житель стоит на островке или на берегу. Житель может стоять на островке только тогда, когда он поднят. Такой островок называется доступным. В начальный момент времени каждый островок опущен, затем островок поднят <span style="white-space: nowrap">_a_</span> моментов времени, затем опущен <span style="white-space: nowrap">_b_</span> моментов времени, поднят <span style="white-space: nowrap">_a_</span> моментов, опущен <span style="white-space: nowrap">_b_</span> <span style="white-space: nowrap">и т.д.</span> Константы <span style="white-space: nowrap">_a_</span> и <span style="white-space: nowrap">_b_</span> задаются отдельно для каждого островка. Например, островок <span style="white-space: nowrap">_C_</span> с <span style="white-space: nowrap">_a_<sub>_C_</sub>=2</span> и <span style="white-space: nowrap">_b_<sub>_C_</sub>=3</span> опущен в момент времени 0, поднят в моменты времени 1 и 2, опущен в моменты времени 3, 4 и 5 <span style="white-space: nowrap">и т.д.</span> В момент времени <span style="white-space: nowrap">_t_+1</span> житель может выбрать островок или берег в пределах 5 ближайших с каждой стороны от его местоположения в момент времени <span style="white-space: nowrap">_t_</span> или остаться на месте (если возможно).

Необходимо вычислить минимальный момент достижения правого берега, если такое достижение возможно.

## Формат входного файла

Первая строка содержит число островков (<span style="white-space: nowrap">5_n_1000</span>). Каждая из последующих <span style="white-space: nowrap">_n_</span> строк содержит два натуральных числа <span style="white-space: nowrap">_a_</span> и <span style="white-space: nowrap">_b_</span>, разделённые пробелом (<span style="white-space: nowrap">1_a_,_b_5</span>). Числа в (<span style="white-space: nowrap">_i_+1</span>)-й строке описывают поведение <span style="white-space: nowrap">_i_</span>-го островка.

## Формат выходного файла

Выведите минимальный момент достижения правого берега или сообщение <span style="font-family: monospace">No</span>, если пересечение реки невозможно.## Формат входного файла Первая строка содержит число островков (<span style="white-space: nowrap">5_n_1000</span>). Каждая из последующих <span style="white-space: nowrap">_n_</span> строк содержит два натуральных числа <span style="white-space: nowrap">_a_</span> и <span style="white-space: nowrap">_b_</span>, разделённые пробелом (<span style="white-space: nowrap">1_a_,_b_5</span>). Числа в (<span style="white-space: nowrap">_i_+1</span>)-й строке описывают поведение <span style="white-space: nowrap">_i_</span>-го островка.