document.addEventListener('DOMContentLoaded', () => {
    const taskInput = document.getElementById('taskInput');
    const addTaskButton = document.getElementById('addTaskButton');
    const taskList = document.getElementById('taskList');
    const filterSelect = document.getElementById('filterSelect');

    let tasks = [];

    addTaskButton.addEventListener('click', () => {
        const taskText = taskInput.value.trim();
        if (taskText) {
            const newTask = {
                text: taskText,
                completed: false
            };
            tasks.push(newTask);
            taskInput.value = '';
            renderTasks();
        }
    });

    filterSelect.addEventListener('change', renderTasks);

    function renderTasks() {
        taskList.innerHTML = '';
        const filter = filterSelect.value;

        const filteredTasks = tasks.filter(task => {
            if (filter === 'completed') return task.completed;
            if (filter === 'incomplete') return !task.completed;
            return true; // 'all'
        });

        filteredTasks.forEach((task, index) => {
            const li = document.createElement('li');
            li.textContent = task.text;
            li.className = task.completed ? 'completed' : 'incomplete';

            const completeButton = document.createElement('button');
            completeButton.textContent = task.completed ? 'Undo' : 'Complete';
            completeButton.className = 'task-button'; // Add this line
            completeButton.addEventListener('click', () => {
            task.completed = !task.completed;
            renderTasks();
        });

            li.appendChild(completeButton);
            taskList.appendChild(li);
        });
    }
});