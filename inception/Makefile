all:
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down --remove-orphans --volumes

re: 
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	sudo rm -rf /home/jghribi/data/wordpress/*
	sudo rm -rf /home/jghribi/data/mariadb/*
	@docker-compose -f srcs/docker-compose.yml down
	@docker system prune -a --force 2>/dev/null
	@docker-compose -f srcs/docker-compose.yml rm -fsv
	@docker volume rm $$(docker volume ls -q) 2>/dev/null
	@docker network rm $$(docker network ls -q) 2>/dev/null
	@docker system prune -af --volumes 2>/dev/null
	



.PHONY: all re down clean