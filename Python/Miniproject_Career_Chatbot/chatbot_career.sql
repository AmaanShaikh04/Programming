GRANT ALL PRIVILEGES ON chatbot_career.* TO 'root'@'localhost';

-- Drop the database if it exists
DROP DATABASE IF EXISTS career_chatbot;

-- Create a new database named career_chatbot
CREATE DATABASE career_chatbot;

-- Use the career_chatbot database
USE career_chatbot;

-- Drop table if it exists for Placements
DROP TABLE IF EXISTS Placements;

-- Drop table if it exists for Masters
DROP TABLE IF EXISTS Masters;

-- Drop table if it exists for Startup
DROP TABLE IF EXISTS Startup;

-- Drop table if it exists for Soft Skill Development
DROP TABLE IF EXISTS Soft_Skill_Development;

-- Table for Placements
CREATE TABLE Placements (
    placement_id SERIAL PRIMARY KEY,
    domain VARCHAR(255) NOT NULL,
    description TEXT NOT NULL,
    year_of_study INT NOT NULL
);

-- Table for Masters
CREATE TABLE Masters (
    masters_id SERIAL PRIMARY KEY,
    domain VARCHAR(255) NOT NULL,
    description TEXT NOT NULL,
    year_of_study INT NOT NULL
);

-- Table for Startup
CREATE TABLE Startup (
    startup_id SERIAL PRIMARY KEY,
    domain VARCHAR(255) NOT NULL,
    description TEXT NOT NULL,
    year_of_study INT NOT NULL
);

-- Table for Soft Skill Development
CREATE TABLE Soft_Skill_Development (
    development_id SERIAL PRIMARY KEY,
    domain VARCHAR(255) NOT NULL,
    description TEXT NOT NULL,
    year_of_study INT NOT NULL
);

--  Placements table
INSERT INTO Placements (domain, description, year_of_study) VALUES 
('Software Development', 'Apply for software development s to gain practical experience in programming, software engineering, and agile development methodologies during your first year.', 1),
('Software Development', 'During your second year, continue gaining experience in software development through s. Focus on expanding your technical skills and contributing to real-world projects.', 2),
('Software Development', 'In your third year, pursue s that offer opportunities for deeper specialization in areas like web development, mobile app development, or backend systems.', 3),
('Software Development', 'As a fourth-year student, seek s that provide leadership opportunities, mentorship, and exposure to advanced technologies and industry best practices.', 4);

INSERT INTO Placements (domain, description, year_of_study) VALUES 
('Data Analysis', 'Start exploring data analysis s early in your academic journey. Gain experience in data manipulation, statistical analysis, and data visualization.', 1),
('Data Analysis', 'In your second year, focus on s that allow you to apply your data analysis skills in practical projects. Look for opportunities to work with real datasets and solve meaningful problems.', 2),
('Data Analysis', 'During your third year, aim for s that provide exposure to advanced analytics techniques, machine learning algorithms, and big data technologies.', 3),
('Data Analysis', 'As a fourth-year student, seek s that offer opportunities to lead data-driven projects, collaborate with cross-functional teams, and communicate insights effectively.', 4);

INSERT INTO Placements (domain, description, year_of_study) VALUES 
('Electrical Engineering', 'Begin exploring electrical engineering s early in your academic career. Gain exposure to circuit design, electronics, and power systems.', 1),
('Electrical Engineering', 'In your second year, focus on s that allow you to apply your theoretical knowledge to practical projects. Look for opportunities to work on circuit prototyping, testing, and troubleshooting.', 2),
('Electrical Engineering', 'During your third year, seek s that provide experience in specialized areas such as control systems, embedded systems, or renewable energy.', 3),
('Electrical Engineering', 'As a fourth-year student, pursue s that offer exposure to advanced topics in electrical engineering, such as VLSI design, power electronics, or signal processing.', 4);

INSERT INTO Placements (domain, description, year_of_study) VALUES 
('Mechanical Engineering', 'Start exploring mechanical engineering s early in your academic journey. Gain hands-on experience in areas like CAD design, materials testing, and manufacturing processes.', 1),
('Mechanical Engineering', 'During your second year, focus on s that allow you to apply your mechanical engineering skills in real-world projects. Look for opportunities to work on product development, prototyping, or failure analysis.', 2),
('Mechanical Engineering', 'In your third year, seek s that provide exposure to specialized areas such as robotics, thermodynamics, or fluid mechanics.', 3),
('Mechanical Engineering', 'As a fourth-year student, pursue s that offer opportunities to lead engineering projects, collaborate with multidisciplinary teams, and apply advanced engineering principles.', 4);

--  Masters table
INSERT INTO Masters (domain, description, year_of_study) VALUES 
('Computer Science Research', 'Consider pursuing a master\'s degree in computer science with a focus on research during your first year. Explore research areas such as artificial intelligence, computer vision, or natural language processing.', 1),
('Computer Science Research', 'In your second year, delve deeper into computer science research by focusing on a specific subfield or problem domain. Work on research projects, publish papers, and collaborate with faculty members.', 2),
('Computer Science Research', 'During your third year, narrow down your research interests and identify potential thesis topics. Seek opportunities to present your research at conferences, participate in research symposiums, and engage with the academic community.', 3),
('Computer Science Research', 'As a fourth-year student, focus on completing your master\'s thesis, defending your research findings, and preparing for potential doctoral studies or industry research positions.', 4);

INSERT INTO Masters (domain, description, year_of_study) VALUES 
('Data Science', 'Start preparing for a master\'s degree in data science during your first year by gaining foundational knowledge in statistics, programming, and data analysis techniques.', 1),
('Data Science', 'In your second year, deepen your understanding of data science concepts and methodologies. Take advanced courses in machine learning, data visualization, and big data technologies.', 2),
('Data Science', 'During your third year, specialize in areas such as predictive modeling, deep learning, or data engineering. Work on data science projects, collaborate with industry partners, and build a strong portfolio.', 3),
('Data Science', 'As a fourth-year student, focus on completing your master\'s thesis or capstone project, showcasing your expertise in data science, and preparing for career opportunities in data-driven industries.', 4);

INSERT INTO Masters (domain, description, year_of_study) VALUES 
('Electrical Engineering', 'Consider pursuing a master\'s degree in electrical engineering to deepen your knowledge and expertise in areas such as power systems, control theory, or telecommunications.', 1),
('Electrical Engineering', 'In your second year, focus on advanced coursework and research projects that align with your career interests and academic goals. Collaborate with faculty members and industry partners on cutting-edge research.', 2),
('Electrical Engineering', 'During your third year, specialize in a specific area of electrical engineering through elective courses, research s, and thesis work. Network with professionals in your field and explore career opportunities.', 3),
('Electrical Engineering', 'As a fourth-year student, focus on completing your master\'s thesis, defending your research findings, and transitioning into advanced roles in industry, academia, or research.', 4);

INSERT INTO Masters (domain, description, year_of_study) VALUES 
('Mechanical Engineering Innovation', 'Explore a master\'s program focusing on innovation in mechanical engineering during your first year. Gain knowledge in areas such as advanced materials, robotics, or sustainable design.', 1),
('Mechanical Engineering Innovation', 'In your second year, deepen your understanding of innovative mechanical engineering concepts and methodologies. Work on interdisciplinary projects, collaborate with industry partners, and develop practical solutions.', 2),
('Mechanical Engineering Innovation', 'During your third year, specialize in areas such as additive manufacturing, renewable energy systems, or smart materials. Conduct research, publish papers, and attend conferences to stay updated on emerging trends.', 3),
('Mechanical Engineering Innovation', 'As a fourth-year student, focus on completing your master\'s thesis or capstone project, showcasing your innovative solutions, and preparing for leadership roles in industry, research, or academia.', 4);

--  Startup table
INSERT INTO Startup (domain, description, year_of_study) VALUES 
('Idea Generation', 'Start generating startup ideas early in your academic journey. Brainstorm potential business concepts based on your interests, skills, and market opportunities.', 1),
('Idea Generation', 'In your second year, refine your startup ideas through market research, customer validation, and feasibility analysis. Identify unique value propositions and target customer segments.', 2),
('Idea Generation', 'During your third year, develop detailed business plans for your startup ideas. Define your product/service offerings, revenue models, and go-to-market strategies.', 3),
('Idea Generation', 'As a fourth-year student, finalize your startup concept, assemble a founding team, and prepare to launch your venture into the market.', 4);

INSERT INTO Startup (domain, description, year_of_study) VALUES 
('Prototype Development', 'Start building prototypes or minimum viable products (MVPs) during your first year. Experiment with different design iterations and gather feedback from potential users.', 1),
('Prototype Development', 'In your second year, refine your prototypes based on user feedback and technical feasibility. Test your MVPs in real-world scenarios to validate key assumptions and features.', 2),
('Prototype Development', 'During your third year, focus on scaling up your prototypes and preparing them for mass production. Collaborate with manufacturers, suppliers, and investors to bring your product to market.', 3),
('Prototype Development', 'As a fourth-year student, ensure that your prototypes meet quality standards, regulatory requirements, and customer expectations. Prepare for commercial launch and market expansion.', 4);

INSERT INTO Startup (domain, description, year_of_study) VALUES 
('Business Launch', 'Launch your startup officially during your first year by establishing a legal entity, such as a sole proprietorship or LLC. Register your business name, obtain necessary permits, and set up basic operations.', 1),
('Business Launch', 'In your second year, focus on building your brand identity, developing marketing materials, and creating an online presence. Launch your website, social media profiles, and promotional campaigns.', 2),
('Business Launch', 'During your third year, execute your go-to-market strategy and start acquiring customers. Build partnerships, attend industry events, and leverage PR opportunities to generate buzz around your startup.', 3),
('Business Launch', "As a fourth-year student, evaluate your startup's performance, analyze key metrics, and iterate on your business model. Seek additional funding, scale your operations, and plan for long-term sustainability.", 4);

INSERT INTO Startup (domain, description, year_of_study) VALUES 
('Growth and Scaling', 'Focus on scaling your startup during your first year by refining your product-market fit and acquiring your first customers. Establish scalable processes and systems to support growth.', 1),
('Growth and Scaling', 'In your second year, expand your customer base, enter new markets, and diversify your revenue streams. Hire key team members, raise capital, and optimize your operations for efficiency.', 2),
('Growth and Scaling', 'During your third year, focus on building strategic partnerships, expanding your product line, and increasing market share. Invest in marketing, sales, and customer success to drive sustainable growth.', 3),
('Growth and Scaling', 'As a fourth-year student, prepare for rapid scaling and international expansion. Evaluate potential exit strategies, such as mergers or acquisitions, and position your startup for long-term success.', 4);

--  Soft_Skill_Development table	
INSERT INTO Soft_Skill_Development (domain, description, year_of_study) VALUES 
('Leadership Skills', 'Develop leadership skills through participation in student organizations, group projects, and volunteer opportunities during your first year.', 1),
('Leadership Skills', 'In your second year, take on leadership roles in clubs, societies, or student government. Delegate tasks, motivate team members, and lead by example.', 2),
('Leadership Skills', 'During your third year, hone your leadership abilities through s, part-time jobs, or community initiatives. Learn to communicate vision, inspire others, and make strategic decisions.', 3),
('Leadership Skills', 'As a fourth-year student, demonstrate leadership potential through campus-wide initiatives, capstone projects, or research collaborations. Prepare to take on leadership roles in your career and community.', 4);

INSERT INTO Soft_Skill_Development (domain, description, year_of_study) VALUES 
('Teamwork and Collaboration', 'Enhance teamwork skills through group assignments, team projects, and extracurricular activities during your first year.', 1),
('Teamwork and Collaboration', 'In your second year, collaborate with diverse teams to solve complex problems, resolve conflicts, and achieve shared goals.', 2),
('Teamwork and Collaboration', 'During your third year, work on interdisciplinary projects, participate in study groups, and engage in peer mentoring to strengthen teamwork abilities.', 3),
('Teamwork and Collaboration', 'As a fourth-year student, demonstrate strong teamwork skills through group presentations, industry s, and collaborative research projects.', 4);

SELECT * FROM Placements;
SELECT * FROM Masters;
SELECT * FROM Startup;
SELECT * FROM Soft_Skill_Development;

