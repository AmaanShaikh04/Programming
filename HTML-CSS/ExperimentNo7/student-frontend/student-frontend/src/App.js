import React, { useState, useEffect } from 'react';
import axios from 'axios';

const App = () => {
  const [students, setStudents] = useState([]);
  const [formData, setFormData] = useState({
    firstName: '',
    lastName: '',
    rollNo: '',
    password: '',
    confirmPassword: '',
    contactNumber: '',
  });

  useEffect(() => {
    axios.get('http://localhost:5000/students').then((response) => {
      setStudents(response.data);
    });
  }, []);

  const handleSubmit = async (e) => {
    e.preventDefault();

    try {
      const response = await axios.post('http://localhost:5000/students', formData);
      setStudents([...students, response.data]);
    } catch (error) {
      console.error('Error creating student:', error);
    }
  };

  const handleDelete = async (id) => {
    try {
      await axios.delete(`http://localhost:5000/students/${id}`);
      setStudents(students.filter((student) => student._id !== id));
    } catch (error) {
      console.error('Error deleting student:', error);
    }
  };

  return (
    <div>
      <h1>Student Registration System</h1>

      <form onSubmit={handleSubmit}>
        {/* Add input fields for the form */}
      </form>

      <table>
        <thead>
          <tr>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Roll No</th>
            <th>Password</th>
            <th>Contact Number</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          {students.map((student) => (
            <tr key={student._id}>
              {/* Display student details in tabular format */}
              <td>{student.firstName}</td>
              <td>{student.lastName}</td>
              <td>{student.rollNo}</td>
              <td>{student.password}</td>
              <td>{student.contactNumber}</td>
              <td>
                <button onClick={() => handleDelete(student._id)}>Delete</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default App;
