while true
do
    read -p "Enter email: " email
    echo
    if [[ "$email" =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$ ]]
    then
        echo "Email address $email is valid."
        break
    else
        echo "Email address $email is invalid."
    fi
done