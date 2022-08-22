#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count;//denotes number of words in a sentence
};

struct paragraph {
	struct sentence* data  ;
	int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
	struct paragraph* data;
	int paragraph_count;//denotes number of paragraphs in a document
};

static void		ft_free_matrix(void **matrix, size_t size);
static size_t	ft_count_vectors(void **matrix);
static char		**ft_split(char const *s, char c);

struct document	get_document(char* text)
{
	struct document		doc;
	struct paragraph	*paragraphs;
	struct sentence		*sentences;
	struct word			*words;
	char				**paragraphs_string;
	char				**sentences_string;
	char				**words_string;
	int					paragraphs_num;
	int					sentences_num;
	int					words_num;
	int					p_counter;
	int					s_counter;
	int					w_counter;

	paragraphs_string = ft_split(text, '\n');
	doc.paragraph_count = ft_count_vectors((void **)paragraphs_string);
	doc.data = malloc(sizeof(struct paragraph) * doc.paragraph_count);
	p_counter = -1;
	paragraphs_num = doc.paragraph_count;
	while (++p_counter < paragraphs_num)
	{
		sentences_string = ft_split(paragraphs_string[p_counter], '.');
		doc.data[p_counter].sentence_count = ft_count_vectors((void **)sentences_string);
		sentences_num = doc.data[p_counter].sentence_count;
		doc.data[p_counter].data = malloc(sizeof(struct paragraph) * (sentences_num));
		s_counter = -1;
		while (++s_counter < sentences_num)
		{
			words_string = ft_split(sentences_string[s_counter], ' ');
			words_num = ft_count_vectors((void **)words_string);
			doc.data[p_counter].data[s_counter].data = malloc(\
				sizeof(struct word) * words_num\
			);
			doc.data[p_counter].data[s_counter].word_count = words_num;
			w_counter = -1;
			while (++w_counter < words_num)
				doc.data[p_counter].data[s_counter].data[w_counter].data = words_string[w_counter];
			free(words_string);
		}
		ft_free_matrix((void **)sentences, sentences_num);
	}
	ft_free_matrix((void **)paragraphs, paragraphs_num);
	return (doc);
}

struct word	kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return (Doc.data[n - 1].data[m - 1].data[k - 1]);
}

struct sentence	kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
	return (Doc.data[m - 1].data[k - 1]);
}

struct paragraph	kth_paragraph(struct document Doc, int k) {
	return (Doc.data[k - 1]);
}

static void	ft_free_matrix(void **matrix, size_t size)
{
	size_t	i;

	i = -1;
	if (matrix != NULL)
	{
		if (size)
		{
			while (++i < size)
				free(matrix[i]);
		}
		else
			while (matrix[++i])
				free(matrix[i]);
		free(matrix);
	}
}

static size_t	ft_count_vectors(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*ptr;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (start >= s_len)
		ptr = malloc(sizeof(char) * 1);
	else if (len > s_len - start)
		ptr = malloc(sizeof(char) * (s_len - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && ((start + i) < s_len) && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	num_of_words(char const *s, char c)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		total++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (total);
}

static char	*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	words;

	if (s != NULL)
	{
		words = num_of_words(s, c);
		final = (char **)malloc(sizeof(char *) * (words + 1));
		if (!(final))
			return (NULL);
		i = 0;
		while (i < words)
		{
			s = next_word(s, c);
			final[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!final[i])
				return (NULL);
			i++;
			s += ft_wordlen(s, c);
		}
		final[words] = NULL;
		return (final);
	}
	return (NULL);
}

void	print_word(struct word w) {
	printf("%s", w.data);
}

void print_sentence(struct sentence sen)
{
	for (int i = 0; i < sen.word_count; i++)
	{
		print_word(sen.data[i]);
		if (i != sen.word_count - 1)
			printf(" ");
	}
}

void print_paragraph(struct paragraph para)
{
	for (int i = 0; i < para.sentence_count; i++)
	{
		print_sentence(para.data[i]);
		printf(".");
	}
}

void print_document(struct document doc)
{
	for (int i = 0; i < doc.paragraph_count; i++)
	{
		print_paragraph(doc.data[i]);
		if (i != doc.paragraph_count - 1)
			printf("\n");
	}
}

char* get_input_text(void)
{
	int		paragraph_count;
	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];

	scanf("%d", &paragraph_count);
	memset(doc, 0, sizeof(doc));
	getchar();
	for (int i = 0; i < paragraph_count; i++)
	{
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1)
			strcat(doc, "\n");
	}

	char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
	strcpy(returnDoc, doc);
	return (returnDoc);
}

int main(void)
{
	char*				text = get_input_text();
	struct document		Doc = get_document(text);
	int					q;

	scanf("%d", &q);
	while (q--)
	{
		int				type;

		scanf("%d", &type);
		if (type == 3)
		{
			int			k, m, n;

			scanf("%d %d %d", &k, &m, &n);
			struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
			print_word(w);
		}

		else if (type == 2)
		{
			int			k, m;

			scanf("%d %d", &k, &m);
			struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
			print_sentence(sen);
		}

		else
		{
			int			k;

			scanf("%d", &k);
			struct paragraph para = kth_paragraph(Doc, k);
			print_paragraph(para);
		}
		printf("\n");
	}
}
