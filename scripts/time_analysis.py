from builtins import print
from subprocess import check_output
from pandas import DataFrame
from tabulate import tabulate
import re

block_sizes = [10, 100, 1000, 2000, 4000]
processors_num = [9, 10, 11, 12]

results = DataFrame(columns=["processor_num", "block_size", "microseconds"])

for i in range(len(block_sizes)):
    for j in range(len(processors_num)):
        print('mpirun -qn {} ../cmake-build-debug/PP_Final_Main {} ../images/1gb.png && '.format(processors_num[j],
                                                                                                 block_sizes[i]))
        """
        microseconds = check_output(
            ['mpirun -qn {} ../cmake-build-debug/PP_Final_Main {} ../images/1gb.png'.format(processors_num[j],
                                                                                            block_sizes[i])],
            shell=True)
        result = re.search('([0-9]+)', str(microseconds))
        results = results.append(
            {"processor_num": processors_num[j], "block_size": block_sizes[i] * block_sizes[i],
             "microseconds": result.group(0)},
            ignore_index=True)
        print(tabulate(results, headers='keys', tablefmt='psql'))
        results.to_csv(path_or_buf="results.csv", index=False)
        """
