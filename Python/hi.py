import pandas as pd

# Data for the Excel file
data = {
    "Section": [
        "Basic Knowledge Questions",
        "Basic Knowledge Questions",
        "Basic Knowledge Questions",
        "Basic Knowledge Questions",
        "Scenario-Based Questions",
        "Scenario-Based Questions",
        "Scenario-Based Questions",
        "Practical Task Questions",
        "Practical Task Questions",
        "Practical Task Questions",
        "Behavioral Questions",
        "Behavioral Questions",
    ],
    "Question": [
        "What is the difference between penetration testing and vulnerability assessment?",
        "What are the different types of penetration testing?",
        "Explain the OWASP Top 10 and its importance.",
        "What tools do you use for ethical hacking, and why?",
        "A client’s website is suspected to be vulnerable to SQL Injection. How would you confirm this?",
        "How would you handle a situation where a client denies the existence of a vulnerability you’ve discovered?",
        "During a penetration test, you discover sensitive client data (e.g., credentials or financial data). What are your next steps?",
        "Perform a basic network scan on a provided virtual environment.",
        "Identify vulnerabilities in a simple web application.",
        "Write a basic script (e.g., Python or Bash) to automate a common pentesting task.",
        "Describe a challenging ethical hacking project you worked on and how you overcame obstacles.",
        "How do you keep your skills up to date in such a rapidly evolving field?",
    ],
    "Expected Answer": [
        "Penetration testing is an active attempt to exploit vulnerabilities to evaluate system security, while vulnerability assessment identifies and reports potential vulnerabilities without exploiting them.",
        "Black-box, white-box, and gray-box testing, with an explanation of how each provides different levels of access and knowledge about the system.",
        "OWASP Top 10 is a list of the most critical security risks to web applications, such as SQL Injection, Cross-Site Scripting (XSS), and Security Misconfiguration.",
        "Tools like Burp Suite, Metasploit, Nmap, Nessus, Wireshark, and others, with reasons for usage.",
        "Use tools like sqlmap or manual techniques (e.g., entering SQL payloads like ' OR 1=1-- in input fields) while ensuring client consent and respecting ethical guidelines.",
        "Present detailed evidence (screenshots, logs, POCs), explain the risk, and provide remediation steps. Maintain professionalism and a client-focused approach.",
        "Secure the data, document the discovery, and report it immediately to the client in a confidential manner, ensuring compliance with ethical guidelines.",
        "Use Nmap to identify open ports, services, and potential vulnerabilities.",
        "Use tools like Burp Suite or manual testing methods to find issues like XSS or insecure cookies.",
        "A working script that demonstrates an understanding of automation and scripting basics.",
        "Specific details about the project, challenges faced, steps taken to resolve issues, and lessons learned.",
        "Mention of relevant certifications (CEH, OSCP, etc.), participation in CTFs, reading security blogs, or contributing to open-source projects.",
    ],
    "Red Flags": [
        "Confusion between the two; inability to differentiate or explain clearly.",
        "Inability to list or explain these testing types.",
        "Lack of familiarity with OWASP or incorrect/missing risks.",
        "Mention of obsolete or unreliable tools; no clear reasoning behind tool selection.",
        "Over-reliance on tools without understanding manual techniques; lack of emphasis on client consent and legal boundaries.",
        "Becoming defensive or argumentative; inability to communicate findings effectively.",
        "Mishandling or failing to report the data appropriately; discussing it without a clear plan.",
        "Inability to use Nmap effectively; incorrect interpretation of results.",
        "Over-reliance on automated tools without understanding how the vulnerabilities work.",
        "Inability to write or debug a simple script; lack of logical flow in the script.",
        "Vagueness or fabrication of experiences; failure to demonstrate problem-solving skills.",
        "No clear strategy for continuous learning; reliance on outdated knowledge.",
    ],
}

# Convert data to DataFrame
df = pd.DataFrame(data)

# Save to an Excel file
file_path = "Pentesting_Interview_Questions.xlsx"
df.to_excel(file_path, index=False)
