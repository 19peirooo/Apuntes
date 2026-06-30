window.addEventListener('load', () => load_data());

let num_tasks = 0

function load_data() {
    const task_list = document.getElementById("task_list");
    const tasks = localStorage.getItem('tasks');
    if (tasks) {
        const json_tasks = JSON.parse(tasks);
        json_tasks.forEach(task => {
            if (task.task_status !== 'deleted'){
                const li = document.createElement('li');
                li.innerText = task.task;
                li.id = task.task_id;
                
                if (task.task_status == 'completed') {
                    li.classList.toggle('completed');
                    li.addEventListener('click',() => delete_task(task.task_id));
                } else {
                    li.addEventListener('click', () => task_completed(task.task_id))
                }
                task_list.appendChild(li);
            }
            num_tasks++;
        });
    }    
}

function add_task() {
    const task_list = document.getElementById("task_list");
    const task_input = document.getElementById("task_input");
    const tasks_stored = JSON.parse(localStorage.getItem('tasks')) || [];
    const task = task_input.value;

    const li = document.createElement("li");
    const task_id = "task_"+num_tasks
    li.id = task_id;
    num_tasks++;
    li.innerText = task;
    li.addEventListener('click', () => task_completed(task_id))
    const json_task = {'task_id':task_id,'task': task, 'task_status':'created'};
    tasks_stored.push(json_task);
    task_list.appendChild(li);
    localStorage.setItem("tasks",JSON.stringify(tasks_stored));
    task_input.value = "";
}

function task_completed(task_id) {
    const task = document.getElementById(task_id)
    const tasks_stored = JSON.parse(localStorage.getItem('tasks'));
    if (task) {
        task.classList.toggle('completed');
        task.addEventListener('click',() => delete_task(task_id));
        //Buscar el task en local storage
        tasks_stored.forEach(task => {
            if (task.task_id == task_id) {
                task.task_status = 'completed';
            }
        })
        localStorage.setItem("tasks", JSON.stringify(tasks_stored));
    }
}

function delete_task(task_id) {
    const task = document.getElementById(task_id);
    const tasks_stored = JSON.parse(localStorage.getItem('tasks'));
    if (task) {
        task.remove()
        tasks_stored.forEach(task => {
            if (task.task_id == task_id) {
                task.task_status = 'deleted';
            }
        })
        localStorage.setItem("tasks", JSON.stringify(tasks_stored));
    }
}
