
set ns [new Simulator]


$ns color 0 blue
$ns color 1 red



set nf [open out.nam w]
$ns namtrace-all $nf

#Finish procedure to open file using nam to visulaize our network
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
}

#Defining Nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]



$ns duplex-link $n0 $n2 2Mb 10ms DropTail 
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail


#putting a limit to nodes link
$ns queue-limit $n0 $n2 10
$ns queue-limit $n1 $n2 10
$ns queue-limit $n2 $n3 10

$ns duplex-link-op $n2 $n0 orient left-up 
$ns duplex-link-op $n2 $n1 orient left-down 
$ns duplex-link-op $n2 $n3 orient right


$ns duplex-link-op $n2 $n3 queuePos 0.5
$ns duplex-link-op $n1 $n2 queuePos 0.5
$ns duplex-link-op $n0 $n2 queuePos 0.5


set tcp0 [new Agent/TCP]
set sink0 [new Agent/TCPSink]
$ns attach-agent $n1 $tcp0
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0

set udp0 [new Agent/UDP]
set null0 [new Agent/Null]
$ns attach-agent $n0 $udp0
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0

set ftpSender1 [new Application/FTP]

$ftpSender1 attach-agent $tcp0

set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 1000 (in Bytes)

$cbr0 set interval_ 0.01 (one packet in each 0.005 seconds)

$cbr0 attach-agent $udp0


$udp0 set fid_ 1
$tcp0 set fid_ 0

$ns at 0.5 "$ftpSender1 start"

$ns at 4.0 "$ftpSender1 stop"

$ns at 1.0 "$cbr0 start"

$ns at 4.5 "$cbr0 stop"

$ns at 5.0 "finish"

$ns run
