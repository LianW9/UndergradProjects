public class toDoList{
    public class Task{
        private String name;
        private int priority;
        private int estMinsToComplete;

    public Task(String initiallName, int initialPriority, int initialestMinToComplete){
        name = initiallName;
        priority = initialPriority;
        estMinsToComplete = initialestMinToComplete;
    }
    public String getName(){
        return name;
    }
    public int getPriority(){
        return priority;
    }
    public int getEstMinsToComplete(){
        return estMinsToComplete;
    }
    public void setName(String newName){
        name = newName;
    }
    public void setEstMinsToComplete(int newEstMinsToComplete){
        estMinsToComplete = newEstMinsToComplete;
    }
    public String toString(){
        return "(" + name + "," + priority + "," + estMinsToComplete + ")";
    }
    public int increasePriority(int amount){
        if(amount < 0){
            return priority;
        }
        priority += amount;
        return priority;
    }
    public int decreasePriority(int amount){
        if(priority - amount <=0){
            priority = 0;
            return priority; 
        }
        priority -= amount;
        return priority;
    }
    }
    public class HoneyToDo{
        private String tasks[];
        private int numTasks;
        private int INITIAL_CAPACITY;
    public HoneyToDo(int initialTasks[], int initialNumTasks, int initialINITIAL_CAPACITY){
        INITIAL_CAPACITY = initialINITIAL_CAPACITY;
        tasks = new String [INITIAL_CAPACITY];
        numTasks = 0;
    }
    public String toString(){
        String answer = " ";
        for(int i = 0; i < tasks.length; i++){
            answer += tasks[i];
        }
        return answer;
    }
    public int find(String name){
        for(int i = 0; i < tasks.length; i++){
            if(name.equalsIgnoreCase(tasks[i]) == true){
                return i;
            }
        }
        return -1;
    }
    public void addTask(){
        if(numTasks == tasks.length){
            String[] newTasks = new String[numTasks];
            tasks = newTasks;
        }
        String[] newArray = new String[numTasks];
        for(int i = 0; i < newArray.length; i++){
            tasks[i] += newArray[i];
        }
    }
    public int totalTime(){
        int [] time = new int[numTasks];
        int count = 0;
        Task amount = new Task(null, numTasks, count);
        for(int i = 0; i < tasks.length; i++){
            time[i] += amount.getEstMinsToComplete();
        }
        for(int j = 0; j < time.length; j++){
            count += time[j];
        }
        return count;
    }
    public int shortestTime(){
        int count = 0;
        int [] time = new int[numTasks];
        Task amount = new Task(null, numTasks, count);
        for(int i = 0; i < tasks.length; i++){
            time[i] += amount.getEstMinsToComplete();
        }
        for(int i = 0; i < time.length; i++){
            if(time[i] < count){
                count = time[i];
            }
            if(tasks.length == 0){
                return -1;
            }
        }
        return count;
    }
    public String[] completeTask(int index){
        if(index < 0 || index >= tasks.length){
            return null;
        }
        for(int i =0; i < tasks.length; i++){
            if(i == index){
                tasks[i] = tasks[i-1];
            }
        }
        return tasks;
    }
    public String getTask(int index){
        for(int i = 0; i < tasks.length; i++){
            if(i != index){
                return null;
            }
        }
        return tasks[index];
    }
    }
}