# <h1 align="center"><a href="https://github.com/AtibQur/push_swap/blob/main/push_swap.pdf" target="_blank">Philosophers</a>🍝🍴</h1>
<p><img align="right" src="./img/score.png" alt="Score" width="125" height="125"></p>

<h2> Description Push_swap</h2>
This projects involves making use of threads and mutexes. 
By precisely timing a group of philosphers on when to pick a fork and spaghetti without dying from hunger.

To succeed this assignement:
<li>One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.</li>
<li>The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.</li>
<li>There are also forks on the table. There are as many forks as philosophers.</li>
<li>• There are also forks on the table. There are as many forks as philosophers.</li>
<li>When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.</li>
<li>Every philosopher needs to eat and should never starve.</li>
<li>Philosophers don’t speak with each other.</li>
<li>Philosophers don’t know if another philosopher is about to die.</li>
<li>No need to say that philosophers should avoid dying!</li>

<h2>Installation ⚙️</h2>
*To build the programm there is only a few steps: First of all, you can download the repository through the following steps in any shell of your preference:*
<br>
<pre>
git clone git@github.com:AtibQur/push_swap.git
cd philosophers
make
</pre>
These commands will compile everything and a executable <em>"push_swap"</em> should be created.
<br><br>
<h2>Usage 🛠️</h2>
<p>To compile the program, run the following command:</p>
<pre>
cd philosophers && make
</pre>
After creating the executable, the function is ready for use. This function only takes integers and will return errors if a non numeric character is used.
<br></br>

3rd party helpers
educative  --> https://www.educative.io/answers/how-to-create-a-simple-thread-in-c
MichelleJiam tester --> https://github.com/MichelleJiam/LazyPhilosophersTester/tree/9819a70a3f6bab412d6615d26d625d648fa3695a
Dining philosophers problem wikipedia --> https://en.wikipedia.org/wiki/Dining_philosophers_problem