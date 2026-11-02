## baseline_loop

- Measurement Methodology

For this program we calculated the execution time, and counted it's iterations.
We did it 3 times to verrify consistency.
Giving us the folowing results:

Iterations: 100000000
Execution time: 0.057967 seconds
Iterations: 100000000
Execution time: 0.057378 seconds
Iterations: 100000000
Execution time: 0.057413 seconds

- Observed Performances Differences

Between the 3 mesurements we can see, for a similar number of iteration,
an execution time ocillating between 0.057967 and 0.057378 second.

- Relation Between Runtime and Energy Consumption

For this mesurement we can see a program with the same number of iterations each time,
and an execution  that doesn't vary much from one execution to the other.
Therefore we can asume with the provided metrics that energy consumption doesn't vary too much
from one execution to the other.

- Limitation of the Experiment

For this experiment we only mesured the number of iterations and the execution time of our program.
We are therefore lacking data about the actual consumption of each execution of the program.

- Practical Engineering Takeaway

For this particular occurence I will center myself more ont the Mesurement Methodology.
To get sharper result it would be useful to gather data about the actual Ressource Consumption.
For example Cpu runtime.

## comparison_algorithms

- Measurement Methodology

For this program we reviewed the iteration count and execution time of two functions that count even numers.
We did 3 tries as a check for consistency.
The results are as follows :

Naive algorithm result: 625025000
Naive algorithm time: 0.491317 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000020 seconds
Naive algorithm result: 625025000
Naive algorithm time: 0.495264 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000019 seconds
Naive algorithm result: 625025000
Naive algorithm time: 0.501173 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000020 seconds

- Observed Performances Differences

As the results state we can see that:
Single-pass algorithm is more efficient in every measured way.
With an iteration count of 25000 on evry test against 625025000 for Naive algorithm,
And an execution time occilating between 0.000020s and 0.000019s against about 0.5s average for Naive algorithm.

- Relation Between Runtime and Energy Consumption

With the chosen metrics we can see that Naive algorithm has a runtime 25000 times higher than Single-pass algorithm,
and an iteration count 25001 times higher.
We can therefore clearly state that Single-pass algorithm is the most efficent energy consumption wise.

- Limitations of the Experiment

We stoped at 3 tries for consistency and tested out the algorithms in only one environment,
we also did not get metrics about actual ressource consumption.
Yet the results show enough of a difference to get a good apreciation when comparing efficiency.

- Practical Engeneering Takeaway

We shall keep Single-pass algorithm since it is about as shown by our metrics 25000 times more efficent.
If more tests shall be runed however I would advise for ressources consumption verification.

## instrumentation_lab

- Measurement Methodology

For this test we took each function of our program and mesured their execution time and their total.
We did 3 tests as a check for consistency.
Results are as follows:

TOTAL seconds: 0.000187
BUILD_DATA seconds: 0.000063
PROCESS seconds: 0.000086
REDUCE seconds: 0.000038
TOTAL seconds: 0.000196
BUILD_DATA seconds: 0.000067
PROCESS seconds: 0.000091
REDUCE seconds: 0.000038
TOTAL seconds: 0.000185
BUILD_DATA seconds: 0.000062
PROCESS seconds: 0.000085
REDUCE seconds: 0.000038

- Observed Performance Differencies

We can see according to our results that our program runs sensibly at the same speed each time,
And that the most time consuming are from most to least: PROCESS > BUILD > REDUCE

- Relation Between Runtime and Energy Consumption

According to the metrics we have, detailed runtime, we can state that the energy cost repartition
of our program goes like so going from highest to lowest: PROCESS > BUILD > REDUCE

- Limitaitions of the Experiment

Limited metrics since we only have the detailed execution time. We could get sharper results
by adding number of iteration and ressources consumption.

- Practical Engineering Takeaway

With our limited metrics, I will conclude by saying that any opperation of optimization should
focus on PROCESS and BUILD since they are the most time consuming tasks in the program.