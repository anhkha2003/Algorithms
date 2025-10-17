import multiprocessing
import subprocess
import time
 
num_workers = 5
 
processed_tasks = multiprocessing.Value('i', 0)
 
def worker(task):
    worker_id = multiprocessing.current_process().name
    index, test_case = task
    print(f"Worker {worker_id} processing task {index}", flush=True)
    input_data = f"1\n{test_case}\n"
 
    start_time = time.time()
    process = subprocess.Popen(
        ['main.exe'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
 
    output, error = process.communicate(input=input_data)
    if error:
        print(f"Error in processing test case {index}: {error}")
 
    elapsed_time = round(time.time() - start_time, 2)
    print(f"Worker {worker_id} completed task {index} ({elapsed_time}s)", flush=True)
 
    return index, output.strip()
 
def main():
    # Read the input file
    with open('input.txt', 'r') as f:
        lines = f.readlines()
 
    T = int(lines[0].strip())
 
    # TODO: fix this for each test format
    test_cases = []
    cur_line = 1
    for z in range(T):
        test_cases.append(''.join(lines[cur_line:cur_line + 1]))
        cur_line += 1

    # Create tasks
    tasks = [(i, test_case.strip()) for i, test_case in enumerate(test_cases)]
 
    # Create and start worker pool
    with multiprocessing.Pool(processes=num_workers) as pool:
        results = pool.map(worker, tasks)
 
    # Sort results by index
    results.sort(key=lambda x: x[0])
 
    # Write results to the output file
    with open('output.txt', 'w') as f:
        for idx, result in results:
            f.write(f'Case #{idx + 1}: ')
            f.write(result + '\n')
 
if __name__ == '__main__':
    main()