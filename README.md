# BarberShop
A single-chair barbershop code written in C.
From when it opens in the morning until it closes, customers arrive at random times. If the barber is not busy, he serves a customer immediately, otherwise they must wait in a queue (FIFO order).

The simulation uses the notion of event driven simulation, where
a priority queue of events is ordered in increasing event time.
The event scheduler fetches the earliest event, sets the model time to this event's time, and calls the run method of the process
for which the event was scheduled.
