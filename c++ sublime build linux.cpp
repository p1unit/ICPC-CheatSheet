{
	"shell_cmd": "g++ ${file} -o ${file_path}/${file_base_name}&&gnome-terminal -- bash -c '${file_path}/${file_base_name};read -p \"\nPlease press any key to exit...\"'",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c, source.c++",
    "variants":
    [
    	{
    		"name":"Run with more Memory",
    		"shell":true,
    		"shell_cmd":"g++ ${file} -o ${file_path}/${file_base_name}&&gnome-terminal -- bash -c 'ulimit -s 1000000;${file_path}/${file_base_name};read -p \"\nPlease press any key to exit...\"'"
    	},
    	{
    		"name":"Run with More More Memory",
    		"shell":true,
    		"shell_cmd":"g++ ${file} -o ${file_path}/${file_base_name}&&gnome-terminal -- bash -c 'ulimit -s 2000000;${file_path}/${file_base_name};read -p \"\nPlease press any key to exit...\"'"
    	},
    	{
    		"name":"Run with Very More More Memory",
    		"shell":true,
    		"shell_cmd":"g++ ${file} -o ${file_path}/${file_base_name}&&gnome-terminal -- bash -c 'ulimit -s 4000000;${file_path}/${file_base_name};read -p \"\nPlease press any key to exit...\"'"
    	}
    ]
}
	
