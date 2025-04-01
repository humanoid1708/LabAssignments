function fetchStudents() {
    fetch('/students')
        .then(response => response.json())
        .then(data => {
            let studentsDiv = document.getElementById('studentsList');
            studentsDiv.innerHTML = JSON.stringify(data);
        });
}
