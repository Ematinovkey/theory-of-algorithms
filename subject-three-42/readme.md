## Задача 42. Соревнования

| параметр  | значения  |
|---|---|
| Имя входного файла:     | input.txt     |
| Имя выходного файла:    | output.txt    |
| Ограничение по времени: | 1c            |
| Ограничение по памяти:  | нет           |

## Условие

Для выявления лучшего программиста в стране решили провести соревнования по программированию. Для участия в соревнованиях было зарегистрировано <span style="white-space: nowrap">_n_</span> человек. Для выявления лучшего программиста было проведено три соревнования, в каждом из которых участвовали все зарегистрировавшиеся (известно, что никакие два участника не имели одинаковые результаты в одном и том же соревновании). И вот перед жюри конкурса встал один вопрос: как же, всё-таки, выбрать лучшего? Будем говорить, что участник <span style="white-space: nowrap">_a_</span> лучше участника <span style="white-space: nowrap">_b_</span>, если участник <span style="white-space: nowrap">_a_</span> во всех соревнованиях занял места выше, чем участник <span style="white-space: nowrap">_b_</span>. Назовём участника <span style="white-space: nowrap">_c_</span> лучшим, если нет такого участника, который лучше участника <span style="white-space: nowrap">_c_</span>. С целью выявления числа лучших участников жюри конкурса наняло вас. Помогите жюри найти число лучших среди всех зарегистрированных участников.

## Формат входного файла

Первая строка содержит число <span style="white-space: nowrap">_n_</span> зарегистрированных участников (<span style="white-space: nowrap">1≤*n*≤100 000</span>). Далее, в последующих <span style="white-space: nowrap">_n_</span> строках записаны по три числа <span style="white-space: nowrap">_a_<sub>_i_</sub></span>, <span style="white-space: nowrap">_b_<sub>_i_</sub></span>, <span style="white-space: nowrap">_c_<sub>_i_</sub></span> (<span style="white-space: nowrap">1≤*a*<sub>_i_</sub>,*b*<sub>_i_</sub>,*c*<sub>_i_</sub>≤*n*</span>) — места в каждом из трёх соревнований <span style="white-space: nowrap">_i_</span>-го участника.

## Формат выходного файла

Выведите число лучших участников.
