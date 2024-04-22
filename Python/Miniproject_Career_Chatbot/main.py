import mysql.connector
import MySQLdb
import spacy
from nltk.corpus import stopwords
import requests
import webbrowser

# Load the spaCy model for natural language processing
nlp = spacy.load("en_core_web_sm")

"""
    function name: connect_to_database
    function description: Establishes a connection to the MySQL database.
    Parameters:
    - host (str): Database host address.
    - user (str): Username for database authentication.
    - password (str): Password for database authentication.
    - database (str): Name of the database to connect to.
    Return Value:
    - conn (MySQLConnection): MySQL database connection object.
    - cursor (MySQLCursor): Cursor object to execute SQL queries.
"""
def connect_to_database(host, user, password, database):

    conn = MySQLdb.connect(host="localhost", user="root", password="pandasql", database="career_chatbot")
    cursor = conn.cursor()
    return conn, cursor

"""
    function name: extract_keywords
    function description: Extracts keywords from the user query after lemmatization and removing stopwords.
    Parameters:
    - query (str): User input query.
    Return Value:
    - keywords (list): List of lemmatized, non-stopword keywords extracted from the query.
"""

def extract_keywords(query):

    doc = nlp(query)  # Use spaCy for lemmatization
    stop_words = set(stopwords.words('english'))
    keywords = [token.lemma_.lower() for token in doc if token.is_alpha and token.lemma_.lower() not in stop_words]
    return keywords

"""
    function name: search_data
    function description: Searches for relevant information in the MySQL database based on extracted entities from the user query.
    Parameters:
    - user_query (str): User input query.
    - cursor (MySQLCursor): The cursor object to execute SQL queries.
    - target_category (str): Target category of the search (e.g., Startup, Placement, Masters, Soft Skills Development).
    - target_domain (str): Target domain within the category.
    - user_year_of_study (int): User's year of study.
    - max_results (int, optional): Maximum number of results to return. Defaults to 5.
    Return Value:
    - matched_results (list): List of tuples containing matched results (domain, year_of_study, description).
"""

def search_data(user_query, cursor, target_category, target_domain, user_year_of_study, max_results=5):
    keywords = extract_keywords(user_query)
    matched_results = []

    # Build a dynamic SQL query with multiple OR conditions for each keyword
    query_str = f"SELECT domain, year_of_study, description FROM {target_category} WHERE {' OR '.join(['description COLLATE utf8mb4_general_ci LIKE %s'] * len(keywords))}"
    params = ['%' + keyword + '%' for keyword in keywords]

    if target_category:
        print(target_domain)
        query_str += " AND domain = %s"
        params.append(target_domain)

    if user_year_of_study:
        query_str += " AND year_of_study = %s"
        params.append(user_year_of_study)

    cursor.execute(query_str, params)
    results = cursor.fetchall()

    for domain, year_of_study, description in results:
        # Check if all criteria match
        if domain.lower() == target_domain.lower() and year_of_study == user_year_of_study:
            matched_results.append((domain, year_of_study, description))

    # Limit the number of results to be displayed
    return matched_results[:max_results]

"""
    function name: display_results
    function description: Displays the matched results in a formatted manner.
    Parameters:
    - results (list): List of tuples containing matched results (domain, year_of_study, description).
"""

def display_results(results):
    print("-" * 60)
    for result in results:
        domain, year_of_study, description = result
        print(f"Domain: {domain.capitalize()}")
        print(f"Year of Study: {year_of_study}")
        print(f"Description: {description}")
        print("-" * 60)

def is_internet_available():
    try:
        # Try to make a simple HTTP request to a reliable website
        response = requests.get("http://www.google.com", timeout=5)
        response.raise_for_status()
        return True
    except requests.RequestException:
        return False


def main():
    # Database configuration
    db_host = "localhost"
    db_user = "root"
    db_password = "pandasql"
    db_database = "chatbot_career"

    # Establish a connection to the MySQL database
    conn, cursor = connect_to_database(db_host, db_user, db_password, db_database)

    print("Welcome to the Career Guidance Chatbot.")

    while True:
        # Collect user's name
        user_name = input("Please enter your name: ").strip()

        # Collect user's year of study
        while True:
            try:
                user_year_of_study = int(input("Please enter your year of study (e.g., 1, 2, 3, 4): ").strip())
                break
            except ValueError:
                print("Invalid input. Please enter a valid year of study.")

        print("Thank you, " + user_name + ". Let's continue.")

        while True:
            print("You can ask questions about Startup, Placements, Masters, and Soft Skills Development.")
            print("Type 'exit' to quit.")
            user_query = input("You: ").strip().lower()

            if user_query.lower() == 'exit':
                print("Chatbot: Goodbye! Have a great day!")
                return

            if user_query in ['hi', 'hello', 'hey']:
                print("Chatbot: Hello! How can I assist you today?")
                continue
            elif user_query in ['bye', 'goodbye']:
                print("Chatbot: Goodbye! If you have more questions in the future, feel free to return.")
                return

            target_category = None

            if 'startup' in user_query:
                target_category = 'Startup'
            elif 'placement' in user_query:
                target_category = 'Placements'
            elif 'master' in user_query:
                target_category = 'Masters'
            elif 'soft' in user_query:
                target_category = 'Soft_Skill_Development'

            if target_category:
                print(f"Chatbot: Great choice! Now, let's select the domain within {target_category} you're interested in:")
                if target_category == 'Startup':
                      print("1. Idea Generation")
                      print("2. Prototype Development")
                      print("3. Business Launch")
                      print("4. Growth and Scaling")
                elif target_category == 'Placements':
                      print("1. Software Development")
                      print("2. Data Analysis")
                      print("3. Electrical Engineering")
                      print("4. Mechanical Engineering")
                elif target_category == 'Masters':
                      print("1. Computer Science Research")
                      print("2. Data Science")
                      print("3. Electrical Engineering")
                      print("4. Mechanical Engineering Innovation")
                elif target_category == 'Soft_Skill_Development':
                      print("1. Leadership Skills")
                      print("2. Teamwork and Collaboration")
                print("Type 'back' to change the year of study or 'exit' to quit.")

                while True:
                    domain_choice = input("Enter the number corresponding to your domain choice: ").strip()

                    if domain_choice.lower() == 'back':
                        break

                    if domain_choice.lower() == 'exit':
                        print("Chatbot: Exiting domain selection.")
                        return

                    if target_category == 'Startup' and domain_choice in ['1', '2', '3', '4']:
                        domain_tables = {
                            '1': 'Idea Generation',
                            '2': 'Prototype Development',
                            '3': 'Business Launch',
                            '4': 'Growth and Scaling'
                        }
                        target_domain = domain_tables[domain_choice]
                        break
                    elif target_category in ['Placements'] and domain_choice in ['1', '2', '3', '4']:
                        domain_tables = {
                            '1': 'Software Development',
                            '2': 'Data Analysis',
                            '3': 'Electrical Engineering',
                            '4': 'Mechanical Engineering'
                        }
                        target_domain = domain_tables[domain_choice]
                        break
                    elif target_category in ['Masters'] and domain_choice in ['1', '2', '3', '4']:
                        domain_tables = {
                            '1': 'Computer Science Research',
                            '2': 'Data Science',
                            '3': 'Electrical Engineering',
                            '4': 'Mechanical Engineering Innovation'
                        }
                        target_domain = domain_tables[domain_choice]
                        break
                    elif target_category == 'Soft_Skill_Development' and domain_choice in ['1', '2']:
                        domain_tables = {
                            '1': 'Leadership Skills',
                            '2': 'Teamwork and Collaboration'
                        }
                        target_domain = domain_tables[domain_choice]
                        break
                    else:
                        print("Invalid input. Please enter a number corresponding to the provided options.")

                if 'target_domain' in locals():
                    try:
                        matched_results = search_data(user_query, cursor, target_category, target_domain, user_year_of_study)
                        if matched_results:
                            display_results(matched_results)
                        else:
                            print("Chatbot: I couldn't find any relevant information.")
                    except (requests.RequestException, webbrowser.Error) as ex:
                        if isinstance(ex, requests.RequestException):
                            print("Chatbot: It seems like I don't have access to the internet. Connect to the internet to get better results.")
                        elif isinstance(ex, webbrowser.Error):
                            print("Chatbot: It seems like there's an issue with the web browser. Make sure you have a web browser installed.")
                    except Exception as e:
                        print(f"Chatbot: An unexpected error occurred: {e}")

            else:
                  print("Chatbot: I'm sorry, I couldn't understand your query.")

            # Offer to change the year of study
            change_year_choice = input("Would you like to switch the user? (yes/no): ").strip().lower()
            if change_year_choice == 'yes':
                break  # Go back to the outer loop to change the year of study
            elif change_year_choice == 'no':
                continue

if __name__ == "__main__":
    main()
