<?php
session_start();

// Simulated database with user data
$users = [
    "1032221184@mitwpu.edu.in" => "password123",
    // Add more user data here
];

$email = $_POST['email'];
$password = $_POST['password'];

if (isset($users[$email]) && $users[$email] === $password) {
    $_SESSION['email'] = $email;
    header("Location: dashboard.php");
    exit();
} else {
    header("Location: index.html");
    exit();
}
?>
