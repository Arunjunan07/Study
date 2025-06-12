import React, { useState } from 'react';
import './App.css';

const AttendanceTracker = () => {
  const [courses, setCourses] = useState([
    {
      id: 1,
      name: 'Mathematics 101',
      students: [
        { id: 101, name: 'Abi', attendance: 'Present' },
        { id: 102, name: 'Babu', attendance: 'Absent' },
        { id: 103, name: 'Sam', attendance: 'Present' },
        { id: 104, name: 'Ramu', attendance: 'Absent' },
      ],
    },
    {
      id: 2,
      name: 'Computer Science 201',
      students: [
        { id: 201, name: 'Somu', attendance: 'Present' },
        { id: 202, name: 'Dev', attendance: 'Absent' },
        { id: 203, name: 'Leo', attendance: 'Present' },
      ],
    },
  ]);

  const [selectedCourseId, setSelectedCourseId] = useState(1);
  const [attendanceFilter, setAttendanceFilter] = useState('All');

  const selectedCourse = courses.find((course) => course.id === selectedCourseId);

  if (!selectedCourse) {
    return <div>Course not found.</div>;
  }

  const handleAttendanceChange = (studentId, attendance) => {
    setCourses((prevCourses) =>
      prevCourses.map((course) =>
        course.id === selectedCourseId
          ? {
              ...course,
              students: course.students.map((student) =>
                student.id === studentId ? { ...student, attendance } : student
              ),
            }
          : course
      )
    );
  };

  const filteredStudents = selectedCourse.students.filter((student) => {
    if (attendanceFilter === 'All') return true;
    return student.attendance === attendanceFilter;
  });

  const presentCount = selectedCourse.students.filter(
    (student) => student.attendance === 'Present'
  ).length;
  const attendancePercentage =
    selectedCourse.students.length > 0
      ? (presentCount / selectedCourse.students.length) * 100
      : 0;

  return (
    <div>
      <h2>Attendance Tracker</h2>
      <select
        value={selectedCourseId}
        onChange={(e) => setSelectedCourseId(parseInt(e.target.value))}
      >
        {courses.map((course) => (
          <option key={course.id} value={course.id}>
            {course.name}
          </option>
        ))}
      </select>
      <h3>{selectedCourse.name}</h3>
      <div>
        <label>
          Filter:
          <select value={attendanceFilter} onChange={(e) => setAttendanceFilter(e.target.value)}>
            <option value="All">All</option>
            <option value="Present">Present</option>
            <option value="Absent">Absent</option>
          </select>
        </label>
      </div>

      <table>
        <thead>
          <tr>
            <th>Student ID</th>
            <th>Student Name</th>
            <th>Attendance</th>
          </tr>
        </thead>
        <tbody>
          {filteredStudents.map((student) => (
            <tr key={student.id}>
              <td>{student.id}</td>
              <td>{student.name}</td>
              <td>
                <select
                  value={student.attendance}
                  onChange={(e) => handleAttendanceChange(student.id, e.target.value)}
                >
                  <option value="Present">Present</option>
                  <option value="Absent">Absent</option>
                </select>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
      <p>Attendance Percentage: {attendancePercentage.toFixed(2)}%</p>
    </div>
  );
};

export default AttendanceTracker;