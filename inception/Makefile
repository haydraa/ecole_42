all:
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down

re: 
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@docker-compose -f srcs/docker-compose.yml down
	@docker-compose -f srcs/docker-compose.yml rm -fsv
	@docker stop $$(docker ps -qa) 2>/dev/null
	@docker rm $$(docker ps -qa) 2>/dev/null
	@docker rmi -f $$(docker images -qa) 2>/dev/null
	@docker volume rm $$(docker volume ls -q) 2>/dev/null
	@docker network rm $$(docker network ls -q) 2>/dev/null
	@docker system prune -a --volumes 2>/dev/null
	@docker system prune -a --force 2>/dev/null

.PHONY: all re down clean