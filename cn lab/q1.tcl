# Get a number from the user
while {1} {
    puts "Enter a number greater than 4: "
    set userInput [gets stdin]

    if {[string is integer $userInput] && $userInput > 4} {
        break
    } else {
        puts "Invalid input!"
    }
}

set number [expr {$userInput}]

if {$number % 2 == 0} {
    for {set i 4} {$i <= $number} {incr i 2} {
        puts $i
    }
} else {
    for {set i 3} {$i <= $number} {incr i 2} {
        puts $i
    }
}