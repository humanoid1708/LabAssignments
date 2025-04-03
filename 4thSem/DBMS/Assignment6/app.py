from flask import Flask, request, jsonify
import mysql.connector

app = Flask(__name__)

db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="yourpassword",
    database="EducationalInstitute"
)
cursor = db.cursor()

@app.route('/students', methods=['GET'])
def get_students():
    cursor.execute("SELECT * FROM Students")
    students = cursor.fetchall()
    return jsonify(students)

@app.route('/enroll', methods=['POST'])
def enroll_student():
    data = request.json
    cursor.execute("INSERT INTO Enrollments (StudentID, CourseID, EnrollmentDate) VALUES (%s, %s, NOW())", 
                   (data['StudentID'], data['CourseID']))
    db.commit()
    return jsonify({"message": "Enrollment successful!"})

if __name__ == '__main__':
    app.run(debug=True)
