### ЗАДАНИЕ 4 (АВС). Сабаев Георгий, БПИ216
# Вариант 17. Задача о картинной галерее.

Вахтер следит за тем, чтобы в картинной галерее одновременно было не более 50 посетителей. Для обозрения представлены 5 картин. Посетитель ходит от картины к картине, и если на картину любуются более чем десять посетителей, он стоит в стороне и ждет, пока число желающих увидеть картину не станет меньше. Посетитель может покинуть галерею. В галерею также пытаются постоянно зайти новые посетители, которые ожидают своей очереди, если та заполнена. 

*Создать многопоточное приложение, моделирующее однодневную работу картинной галереи.*

# Модель

Используем модель приложения "взаимодействующие равные". 

# Алгоритм

Изначально будет создаваться набор из фиксированного (вводится из консоли) числа посетителей у дверей галереи.
Каждому посетителю будет предоставлен поток.
Ограничения на общее число посетителей во всей галерее и у каждой из картин будет регулироваться семафорами.

Каждый посетитель будет пытаться зайти в галерею.
Восле входа он будет случайно решать, уйти из галереи или нет, и если он не уйдет он подойдет к случайной картине.
Когда он посмотрит на картину процесс повторится снова, и так для каждого посетителя пока все не уйдут.