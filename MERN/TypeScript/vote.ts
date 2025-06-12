class VotingSystem {
    private votes: Map<string, number>;
  
    constructor() {
      this.votes = new Map<string, number>();
    }
  
    castVote(candidate: string): string {
      if (!candidate) {
        return "Invalid candidate name.";
      }
      const currentVotes = this.votes.get(candidate) || 0;
      this.votes.set(candidate, currentVotes + 1);
      return `Vote cast for ${candidate}.`;
    }
  
    getWinner(): string {
      let winner = "";
      let maxVotes = 0;
      const winners: string[] = [];
  
      this.votes.forEach((voteCount, candidate) => {
        if (voteCount > maxVotes) {
          maxVotes = voteCount;
          winners.length = 0;
          winners.push(candidate);
        } else if (voteCount === maxVotes) {
          winners.push(candidate);
        }
      });
  
      if (winners.length === 0) {
        return "No votes cast yet.";
      }
  
      if (winners.length === 1) {
        return `The winner is ${winners[0]} with ${maxVotes} votes.`;
      } else {
        return `It's a tie between ${winners.join(", ")} with ${maxVotes} votes.`;
      }
    }
  
    getVoteCount(candidate:string): number | undefined {
      return this.votes.get(candidate);
    }
  
    getAllVotes(): Map<string, number> {
      return this.votes;
    }
  }
  
  const votingSystem = new VotingSystem();
  
  console.log(votingSystem.castVote("Alice"));
  console.log(votingSystem.castVote("Bob"));
  console.log(votingSystem.castVote("Alice"));
  console.log(votingSystem.castVote("Charlie"));
  console.log(votingSystem.castVote("Bob"));
  console.log(votingSystem.castVote("Alice"));
  console.log(votingSystem.castVote("Charlie"));
  console.log(votingSystem.castVote("Charlie"));
  
  console.log(votingSystem.getWinner());
  
  console.log("Alice vote count: ", votingSystem.getVoteCount("Alice"));
  console.log("Bob vote count: ", votingSystem.getVoteCount("Bob"));
  console.log("Charlie vote count: ", votingSystem.getVoteCount("Charlie"));
  console.log("All votes: ", votingSystem.getAllVotes());
  
  const votingSystemTie = new VotingSystem();
  console.log(votingSystemTie.castVote("Alice"));
  console.log(votingSystemTie.castVote("Bob"));
  console.log(votingSystemTie.castVote("Alice"));
  console.log(votingSystemTie.castVote("Bob"));
  console.log(votingSystemTie.getWinner());

  const votingSystemNoVotes = new VotingSystem();
  console.log(votingSystemNoVotes.getWinner());
  

  const votingSystemInvalid = new VotingSystem();
  console.log(votingSystemInvalid.castVote(""));